/**
 * Simple program to demonstrate lifetime of objects
 * with order of executing constructors & destructors
 */
#include <iostream>
class Customer {
  int id;
  std::string name;
  std::string phone;
  double balance;

public:
  Customer(int x, std::string nstr,std::string pstr,double y) : id(x), name(nstr),phone(pstr), balance(y) {
    std::cout << "Customer class constructor : " << id << "\n ";
  }
  Customer(int x, std::string nstr,std::string pstr) : id(x), name(nstr),phone(pstr), balance(100.0) {
    std::cout << "Customer class constructor : " << id << "\n ";
  }
  // rest of constructors, functions
  ~Customer() { std::cout << "Customer class destructor : " << id << "\n "; }
  void display() const {}
};
void test(Customer &);
Customer a0(1000, "Scott", "9845012345", 500.0);
int main() {
  std::cout << "Start of main function\n";
  Customer a1(1001, "Richard", "9845012346", 600.0);
  Customer *p1, *p2;
  p1 = new Customer(1002, "Stevens", "9845012347",700.0);
  p2 = new Customer(1003, "Micahel", "9845012348");
  Customer a2(1004, "Torvalds", "9845012349", 600.0);
  delete p1;
  test(a2);
  delete p2;
  std::cout << "End of main function\n";
  return 0;
}
void test(Customer &ref) {
  std::cout << "Start of test function\n";
  ref.display();
  Customer at(1005, "Lippman", "9845012350", 800.0);
  std::cout << "End of test function\n";
}
