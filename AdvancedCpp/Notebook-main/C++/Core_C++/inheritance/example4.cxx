#include<iostream>
class A {
  int x;

public:
  A(int p) : x(p) { std::cout << "A--ctor\n"; }
  ~A() { std::cout << "A--dtor\n"; }
  void printx() { std::cout << x << "\n"; }
};
class B : public A {
  int y;

public:
  B(int p, int q) : A(p), y(q) { std::cout << "B--ctor\n"; }
  ~B() { std::cout << "B--dtor\n"; }
  void printxy() {
    printx();
    std::cout << y << "\n";
  }
};
class C : public B {
  int z;

public:
  C(int p, int q, int r) : B(p, q), z(r) { std::cout << "C--ctor\n"; }
  ~C() { std::cout << "C--dtor\n"; }
  void printxyz() {
    printxy();
    std::cout << z << "\n";
  }
};
int main() { 
  C c1(10,20,30);
  return 0; 
}
