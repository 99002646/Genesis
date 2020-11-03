#include "banking.h"
#include "account.h"
#include <gtest/gtest.h>
namespace {
class BankingTest : public :: testing::Test
{
protected:
  void SetUp()
	{
		bank.addAccount("101","lakshman",4000);
		bank.addAccount("102","scott",8000);
		bank.addAccount("103","lippman",6000);
	}
  void TearDown() {}
Banking bank;
};
TEST_F(BankingTest,CountAccounts) {
  EXPECT_EQ(3,bank.countAll());
}
TEST_F(BankingTest,AverageBalance) {
  EXPECT_EQ(6000,bank.findAverageBalance());
}
TEST_F(BankingTest,CountByRange) {
  EXPECT_EQ(3, bank.countAccountsByBalanceRange(4000,9000));
}
TEST_F(BankingTest,AddAccount) {
  bank.addAccount("104","Sahana",6000);
  EXPECT_EQ(4,bank.countAll());
  Account *ptr=bank.findAccountById("104");
  EXPECT_NE(nullptr, ptr);
  EXPECT_STREQ("104", ptr->getId().c_str());
  EXPECT_STREQ("Sahana", ptr->getName().c_str());
  EXPECT_EQ(6000, ptr->getBalance());
}
TEST_F(BankingTest,RemoveAccount) {
  bank.removeAccountById("103");
  EXPECT_EQ(2,bank.countAll());
  
}
TEST_F(BankingTest,Accountwithminbalance) {
  Account *minbal=bank.findAccountWithMinBalance();
  EXPECT_NE(nullptr,minbal);
  EXPECT_EQ(4000,minbal->getBalance());

}

}
