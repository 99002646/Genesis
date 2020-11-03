#include<iostream>
class A {
  int x;

public:
  A(int p) : x(p) {}
  void printx() { std::cout << x << "\n"; }
};
class B {
  int y;

public:
  B(int q) : y(q) {}
  void printy() { std::cout << y << "\n"; }
};
class C : public A, public B {
  int z;

public:
  C(int p, int q, int r) : A(p), B(q), z(r) {}
  void printxyz() {
    printx();
    printy();
    std::cout << z << "\n";
  }
};
int main() { 
  C c1(10,20,30);
  c1.printxyz();
  return 0; 
}
