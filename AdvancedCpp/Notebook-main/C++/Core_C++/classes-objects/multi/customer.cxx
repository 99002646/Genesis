#include "customer.h"

const double CALL_RATE = 1.0;

void Customer::init(int x, std::string nstr,std::string pstr, double y) {
  id = x;
  name = nstr;
  phone = pstr;
  balance = y;
}
void Customer::makeCall(int nmins) { balance -= nmins * CALL_RATE; }
void Customer::recharge(double amount) { balance += amount; }
double Customer::getBalance() { return balance; }
void Customer::display() {
  // print id, name, phone, balance
}
