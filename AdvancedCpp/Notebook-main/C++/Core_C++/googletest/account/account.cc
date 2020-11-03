#include<iostream>
#include "account.h"
Account::Account() :
        customerId(0), customerName(""), balance(0) {

}
Account::Account(int id, std::string name, double bal) :
        customerId(id), customerName(name), balance(bal) {

}
Account::Account(const Account& ref) :
        customerId(ref.customerId), customerName(ref.customerName),  
                                              balance(ref.balance) {

}
void Account::credit(double amount) {
    balance += amount;
}
void Account::debit(double amount) {
    //min balance check
    balance -= amount;
}
int Account::getCustomerId() {
    return customerId;
}
std::string Account::getCustomerName() {
    return customerName;
}
double Account::getBalance() const {
    return balance;
}
void Account::display() {
    std::cout << customerId << "," << customerName << "," 
                                         << balance << "\n";
}
