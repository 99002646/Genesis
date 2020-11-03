
#include <iostream>

#include "CreditAccount.h"
CreditAccount::CreditAccount():AccountBase("","",0.0) { }
CreditAccount::CreditAccount(std::string num,std::string name, double balance):AccountBase(num,name,balance) { }
CreditAccount::CreditAccount(std::string num,std::string name):AccountBase(num,name,0.0) { }
void CreditAccount::debit(double balance)
{
    setbalance(+balance);
}
void CreditAccount::credit(double balance)
{
    setbalance(-balance);
}
void CreditAccount::display() const
{
    std::cout<<"Credit Account:";
     std::cout<<AccountBase::getName()<<" "<<AccountBase::getNumber()<<" "<<AccountBase::getBalance()<<std::endl;
}




