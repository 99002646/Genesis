#include "customer.h"
void billingdemo(Customer *ptr);
void transacttest(const Customer &r1);
int main() {
  Customer c1(1001, "Scott", "9845012345", 600.0);

  Customer *ptr;
  ptr = &c1;
  ptr->recharge(100);
  ptr->makeCall(12);
  ptr->display();

  Customer &r1 = c1;
  r1.makeCall(15);
  r1.recharge(150);
  r1.display();

  //simpledemo(c1);   
  billingdemo(&c1);
  transacttest(c1);

  return 0;
}
/*void simpledemo(Customer ob) {  //Try to avoid, performance overhead

}*/
void billingdemo(Customer *ptr) {
  ptr->recharge(100);
  ptr->makeCall(12);
  ptr->display();
}
void transacttest(const Customer &ref) {
 // ref.makeCall(15);
  //ref.recharge(150);
  ref.display();
}
