#include "account.h"
AccountBase::AccountBase():m_accNumber(""),m_accName(""),m_balance(0.0) { }
AccountBase::AccountBase(std::string num,std::string name, double balance):m_accNumber(num),m_accName(name),m_balance(balance) {}
AccountBase::AccountBase(std::string num,std::string name):m_accNumber(num),m_accName(name),m_balance(0.0) { }
AccountBase::AccountBase(const AccountBase& ac):m_accNumber(ac.m_accNumber),m_accName(ac.m_accName),m_balance(ac.m_balance) {}
double AccountBase::getBalance() const
{
    return m_balance;
}
void AccountBase::setbalance(double balance)
{
    m_balance+=balance;
}
std::string AccountBase::getNumber() const
{
    return m_accNumber;
}
std::string AccountBase::getName() const
{
    return m_accName;
}

