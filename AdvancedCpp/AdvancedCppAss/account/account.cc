#include "account.h"
account :: account(): m_name(""),m_num(""),m_bal(0.0){}
account :: account(std::string name,std::string num,double bal): m_name(name),m_num(num),m_bal(bal){}
std::string account :: getId(){
    return m_num;
}
std::string account::getName(){
    return m_name;
}

double account :: debit(double amt){
    m_bal = m_bal-amt;
    return m_bal;
}
double account :: credit(double amt){
    m_bal = m_bal+amt;
    return m_bal;
}
double account :: getBalance(){
    return m_bal;
}
void account :: display(){
    std :: cout << m_name << m_num << m_bal;
}
