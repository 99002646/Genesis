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
  Customer() {
    id = 1001; 
    name = "";
    phone = "";
    balance = 100;
  }
  void makeCall(int nmins) { balance -= nmins * CALL_RATE; }
  void recharge(double amount) { balance += amount; }
  double getBalance() { return balance; }
  void display() {
    // print id,name,phonebalance
  }
};
int main() {
  Customer a1(1001, "Scott", 500.0);
  a1.makeCall(10);
  a1.recharge(100);
  a1.display();

  Customer a2;  
  a2.display();

  return 0;
};
