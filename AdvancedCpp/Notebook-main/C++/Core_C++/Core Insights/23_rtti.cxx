#include<cassert>
#include<iostream>
#include<typeinfo>

class A {
  int x;

public:
  A(int p) : x(p) {}
  virtual void f1() {}
  virtual void f2() {}
};
class B : public A {
  int y;

public:
  B(int p, int q) : A(p), y(q) {}
  virtual void f1() {}
  virtual void f3() {}
};
int main() {
    A *p1, *p2;
    p1 = new A(10);
    p2 = new B(11,12);
    B *p3, *p4;
    p3 = dynamic_cast<B*>(p1);
    //assert(p3!=nullptr);
    p4 = dynamic_cast<B*>(p2);
    assert(p4!=nullptr);

    A a1(15);
    B b1(10,20);
    A& r1 = a1;
    A& r2 = b1;

    //B& r3 = dynamic_cast<B&>(r1);
    B& r4 = dynamic_cast<B&>(r2);

    std::cout << typeid(*p1).name() << "\n";
    std::cout << typeid(*p2).name() << "\n";
    std::cout << typeid(r1).name() << "\n";
    std::cout << typeid(r2).name() << "\n";

    return 0;
}

