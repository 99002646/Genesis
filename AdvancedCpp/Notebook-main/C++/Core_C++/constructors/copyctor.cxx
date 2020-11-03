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
  /*Customer(const Customer& ref) {
    id = ref.id;  
    name = ref.name;
    phone = ref.phone;
    balance = ref.balance;
  }*/
  void makeCall(int nmins) { balance -= nmins * CALL_RATE; }
  void recharge(double amount) { balance += amount; }
  double getBalance() { return balance; }
  void display() { std::cout << id << "," << name << "," << balance << "\n"; }
};
int main() {
  Customer c1(1001, "Scott", "9800012345", 500.0);
  c1.makeCall(10);
  c1.recharge(100);
  // a1.display();

  Customer c2;

  Customer c3(c1);
  c3.display();
  return 0;
};
