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
  double getBalance() { return balance; }
  void display() {
    std::cout << id << "," << name << "," << balance << "\n";
  }
};
int main() {
  Customer c1;
  //c1.init(1001, "Scott","12345", 500.0);
  //c1.setId, c1.setName, c1.setBalance
  c1.display();
  c1.recharge(100);
  c1.makeCall(5);

  Customer c2;
  
  return 0;
};
