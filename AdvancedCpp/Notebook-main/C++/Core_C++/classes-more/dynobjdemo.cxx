#include "customer.h"
#include <cstdio>

void billingdemo(Customer *ptr);
int main() {
  Customer *p1;
  p1 = new Customer(1001, "Scott",  "9845012345", 600.0);
  p1->recharge(100);
  p1->makeCall(12);
  p1->display();

  Customer *p2;
  p2 = new Customer(1002, "Richard",  "9845012345", 600.0);
  billingdemo(p2);

  delete p1;
  p1 = NULL; //nullptr
  delete p2;
  p2 = NULL; //nullptr
  return 0;
}
void billingdemo(Customer *ptr) {
  ptr->recharge(100);
  ptr->makeCall(12);
  ptr->display();
}
