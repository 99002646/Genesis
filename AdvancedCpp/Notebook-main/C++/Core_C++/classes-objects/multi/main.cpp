#include"customer.h"
#include<iostream>
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
  return 0;
};
