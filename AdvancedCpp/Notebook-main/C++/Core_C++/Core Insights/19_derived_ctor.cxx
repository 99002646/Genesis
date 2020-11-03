#include<iostream>
class A {
  int x;

public:
  A(int p) : x(p) {}
  void printx() { std::cout << x << "\n"; }
};
class B : public A {
  int y;

public:
  B(int p, int q) : A(p), y(q) {}
  void printxy() {
    printx();
    std::cout << y << "\n";
  }
};
class C : public B {
  int z;

public:
  C(int p, int q, int r) : B(p, q), z(r) {}
  C(int r):B(5,6), z(r) { }
  //C(int q,int r):B(q), z(r) { }
  C(int q,int r):B(5,q), z(r) { }
  void printxyz() {
    printxy();
    std::cout << z << "\n";
  }
};
int main() { return 0; }
