#include<iostream>

class A {
  int x;

public:
  A(int p):x(p) {}
  void printx() { std::cout << x << "\n"; }
};
class B : public A {
  int y;
public:
  B(int p, int q):A(p),y(q) { }
  void printy() { std::cout << y << "\n"; }
  void printxy() { }
};
int main() {
  A a1(10);
  B b1(11, 22);
  A *p1 = &a1;
  B *p2 = &b1;
  A *p3 = &b1;      //upcasting, allowed, implicit conversion
  //B *p4 = &a1;    //downcasting, not allowed, error by default
  //p4->printy();
   
  A &r1 = a1;
  B &r2 = b1;
  A &r3 = b1;     //upcasting
  //B &r4 = a1;   //downcasting

  A *pa;
  B *pb;
  pa = new B(15,18);    //ok
  //pb = new A(16);       //error
  return 0;
}
void test1(A *ptr) { }      //both A*, B*
void test2(B *ptr) { }      //only B*
void test3(A& ref) { }      //both A&, B&
void test4(B& ref) { }      //only B&