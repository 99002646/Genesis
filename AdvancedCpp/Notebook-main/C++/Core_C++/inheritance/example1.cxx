#include <iostream>
class A {
  int x;

public:
  A():x(5) { }
  A(int p) : x(p) {}
  void printx() { std::cout << x << "\n"; }
};
class B : public A {
  int y;

public:
  B(int p, int q) : A(p), y(q) {
    //x=p;                 //not allowed
    //setx(p);             //not recommended
  }
  B(int q) : A(5), y(q) {
    //setx(5);              //not recommended
  }
  void printy() { std::cout << y << "\n"; }
  void printxy() {
    // std::cout << x << "\n";  //error
    printx(); //getx
    std::cout << y << "\n";
  }
};
int main() {
  A a1(10);
  B b1(11, 12);
  a1.printx();
  b1.printxy();
  b1.printx();
  b1.printy();
  return 0;
}
