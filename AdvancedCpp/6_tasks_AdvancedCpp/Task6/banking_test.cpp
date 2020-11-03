#include "banking.h"
#include"account.h"
#include"SavingsAccount.h"
#include"CreditAccount.h"
#include <gtest/gtest.h>
namespace {

class BankingTest : public ::testing::Test {

  protected:
    void SetUp() { //override {
        bank.addAccount( "1001","ram",5000 );
        bank.addAccount( "1002","sita",8000 );
        bank.addAccount( "1003","john",9000 );
    }
    void TearDown() {
    }
    Banking bank;
};
TEST_F(BankingTest,CountAccounts) {
  EXPECT_EQ(3,bank.countAll());
}
TEST_F(BankingTest,AverageBalance) {
  EXPECT_NE(7333.33,bank.findAverageBalance());
}
TEST_F(BankingTest,CountByRange) {
  EXPECT_EQ(2, bank.countAccountsByBalanceRange(4000,9000));
}
TEST_F(BankingTest,AddAccount) {
  bank.addAccount( "1004","shilpa",6000 );
  EXPECT_EQ(4,bank.countAll());
  SavingsAccount *ptr=bank.findAccountById( "1004" );
  EXPECT_NE(nullptr, ptr);
  EXPECT_STREQ("1004", ptr->getNumber().c_str());
  EXPECT_STREQ("shilpa", ptr->getName().c_str());
  EXPECT_EQ(6000, ptr->getBalance());
}
TEST_F(BankingTest,RemoveAccount) {
  bank.removeAccountById( "1002" );
  EXPECT_EQ(2,bank.countAll());
  SavingsAccount *ptr=bank.findAccountById( "1002" );
  EXPECT_NE(nullptr, ptr);
}
}



