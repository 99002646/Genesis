#include <iostream>
#include <string>

const double CALL_RATE = 1.0;

class Customer {
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
  double getBalance() const { return balance; }
  void display() const;
};
void Customer::display() const {
  // print id,name,phonebalance
}
int main() {
  Customer a1;
  a1.init(1001, "Scott", 500.0);
  a1.makeCall(10);
  a1.recharge(100);
  a1.display();
  std::cout << a1.getBalance() << std::endl;
  //a1.balance=10000;
  //std::cout << a1.balance << "\n";
  return 0;
};
