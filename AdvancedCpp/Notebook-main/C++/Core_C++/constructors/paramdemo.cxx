#include <iostream>
#include <string>

const double CALL_RATE = 1.0;

class Customer {
  int id;
  std::string name;
  std::string phone;
  double balance;

public:
  Customer(int x, std::string nstr, std::string pstr, double y) {
    id = x;
    name = nstr;
    phone = pstr;
    balance = y;
  }
  Customer(int x, std::string nstr, std::string pstr) {
    id = x;
    name = nstr;
    phone = pstr;
    balance = 500;
  }
  void makeCall(int nmins) { balance -= nmins * CALL_RATE; }
  void recharge(double amount) { balance += amount; }
  double getBalance() { return balance; }
  void display() {
    // print id,name,phonebalance
  }
};
int main() {
  Customer c1(1001, "Scott", "9845012345", 500.0);
  c1.makeCall(10);
  c1.recharge(100);
  c1.display();

  Customer c2;  //??

  Customer c3(1002, "Meyers", "9845012345");
  c3.display();
  return 0;
};
