
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount():AccountBase("","",0.0) {}
SavingsAccount::SavingsAccount(std::string num,std::string name, double balance):AccountBase(num,name,balance) {}
SavingsAccount::SavingsAccount(std::string num,std::string name):AccountBase(num,name,0.0) {}
void SavingsAccount::debit(double balance)
{
   setbalance(-balance);
}
void SavingsAccount::credit(double balance)
{
  setbalance(+balance);
}
void SavingsAccount::display() const
{
    std::cout<<"Savings Account:";
    std::cout<<AccountBase::getName()<<" "<<AccountBase::getNumber()<<" "<<AccountBase::getBalance();
}


