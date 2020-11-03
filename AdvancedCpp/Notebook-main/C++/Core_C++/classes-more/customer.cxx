#include "customer.h"
const double CALL_RATE = 1.0;
Customer::Customer(int x, std::string nstr,std::string pstr, double y):id(x),name(nstr),phone(pstr),balance(y) { 
}
Customer::Customer(int x, std::string nstr,std::string pstr):id(x),name(nstr),phone(pstr),balance(500) { 
}
void Customer::makeCall(int nmins) { balance -= nmins * CALL_RATE; }
void Customer::recharge(double amount) { balance += amount; }
double Customer::getBalance() const { return balance; }
void Customer::display() const {
  // print id, name, phone, balance
}
