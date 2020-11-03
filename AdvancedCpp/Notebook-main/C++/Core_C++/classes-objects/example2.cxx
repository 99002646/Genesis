#include <iostream>
#include <string>

const double CALL_RATE = 1.0;

class Customer {
//private:
  int id;
  std::string name;
  std::string phone;
  double balance;

public:
  void init(int x, std::string nstr, std::string pstr, double y) {
    id = x;
    name = nstr;
    phone = pstr;
    balance = y;
  }
  void makeCall(int nmins) { balance -= nmins * CALL_RATE; }
  void recharge(double amount) { balance += amount; }
  double getBalance() { return balance; }
  void display() {
    // print id,name,phonebalance
  }
};
int main() {
  Customer c1;
  c1.init(1001, "Scott", "9845012345", 500.0);
  c1.makeCall(10);
  c1.recharge(100);
  c1.display();
  std::cout << c1.getBalance() << std::endl;
  //c1.balance=10000;
  //std::cout << a1.balance << "\n";
  return 0;
};
