#include <iostream>
#include <string>

/**
 * True initialization of data members in constructors
 * Initializer list for all trivial members
 * Do constructor body will be empty all the times
 * When do constructor body is not empty
 */

const double CALL_RATE = 1.0;

class Customer {
  int id;
  std::string name;
  std::string phone;
  double balance;

public:
  /*Customer(int x, std::string nstr, std::string pstr, double y) {
    std::cout << id << "," << name << "'" << phone << "," << balance << "\n";
    id = x;
    name = nstr;
    phone = pstr;
    balance = y;
  }*/
  Customer(int x, std::string nstr, std::string pstr,double y):id(x),name(nstr),phone(pstr),balance(y) {
    std::cout << id << "," << name << "'" << phone << "," << balance << "\n";
  }
  Customer(int x, std::string nstr, std::string pstr):id(x),name(nstr),phone(pstr),balance(500) { }
  Customer():id(0),name(""),phone(""),balance(0) {}
  //Customer(const Customer& ref):id(ref.id),name(ref.name),phone(ref.phone),balance(ref.balance) {}
  void makeCall(int nmins) { balance -= nmins * CALL_RATE; }
  void recharge(double amount) { balance += amount; }
  double getBalance() { return balance; }
  void display() {
    // print id,name,phonebalance
  }
};
int main() {
  Customer a1(1001, "Scott", "9845012345" ,500.0);
  a1.makeCall(10);
  a1.recharge(100);
  a1.display();

  Customer a2(1002, "Meyers", "9845012346");
  a2.display();

  Customer c3;  

  Customer a4(a1);
  a4.display();  
  return 0;
};
