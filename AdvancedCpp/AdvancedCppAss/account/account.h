#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_

#include <iostream>
class account{
    std::string m_name;
    std::string m_num;
    double m_bal;
public:
    account();
    account(std::string,std::string,double);
    std::string getId();
    std::string getName();
    double getBalance();
    double debit(double);
    double credit(double);

    void display();
};

#endif // __ACCOUNT_H_
