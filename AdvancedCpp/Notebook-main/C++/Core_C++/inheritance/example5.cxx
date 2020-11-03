#include<iostream>
class A {
  int x;

public:
  A(int p) : x(p) { std::cout << "A--ctor\n"; }
  ~A() { std::cout << "A--dtor\n"; }
  void printx() { std::cout << x << "\n"; }
};
class B {
  int y;

public:
  B(int q) : y(q) { std::cout << "B--ctor\n"; }
  ~B() { std::cout << "B--dtor\n"; }
  void printy() { std::cout << y << "\n"; }
};
class C : public A, public B {
  int z;

public:
  C(int p, int q, int r) : A(p),B(q), z(r) { std::cout << "C--ctor\n"; }
  ~C() { std::cout << "C--dtor\n"; }
  void printxyz() {
    printx();
    printy();
    std::cout << z << "\n";
  }
};
int main() { 
  C c1(10,20,30);
  return 0; 
}
