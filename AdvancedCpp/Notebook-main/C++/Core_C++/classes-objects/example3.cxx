#include <iostream>
#include <string>

const double CALL_RATE = 1.0;

class Customer {
  int id;
  std::string name;
  std::string phone;
  double balance;

public:
  void init(int, std::string,std::string, double);
  void recharge(double);
  void makeCall(int);
  void display();
  double getBalance() { return balance; }
};
void Customer::init(int x, std::string nstr,std::string pstr, double y) {
  id = x;
  name = nstr;
  phone = pstr;
  balance = y;
}
void Customer::makeCall(int nmins) { balance -= nmins * CALL_RATE; }
void Customer::recharge(double amount) { balance += amount; }
//double Customer::getBalance() { return balance; }
void Customer::display() {
  // print id, name, phone, balance
}

int main() {
  Customer a1;
  a1.init(1001, "Scott", "9845012345", 500.0);
  a1.makeCall(10);
  a1.recharge(100);
  a1.display();
  std::cout << a1.getBalance() << std::endl;
  //a1.balance=10000;
  //std::cout << a1.balance << "\n";
  return 0;
};
