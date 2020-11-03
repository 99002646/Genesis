class A {
  int x;

public:
  A(int p) : x(p) {}
  void show() { }
  virtual void f1() {}
  virtual void f2() {}
};
class B : public A {
  int y;

public:
  B(int p, int q) : A(p), y(q) {}
  void show() { }
  virtual void f1() {}
  virtual void f3() {}
};
int main() {
  A a1(12);
  B b1(10,20);

  A *p1 = &a1;
  B *p2 = &b1;
  A *p3 = &b1;    //upcasting, implicitly allowed
  //B *p4 = &a1;  //downcasting, not allowed

  A &r1 = b1;     //ok
  //B &r2 = a1;   //not allowed
  r1.show();      //ok

  A *ptr;
  //ptr = new A(10); 
  ptr = new B(11,12);
  ptr->show();
  delete ptr;

  return 0;
}
/** TODO: Analyse virtual tables for
 * A -- f1, f2, f3
 * B -- f1, f3, f4, f5
 * C -- f1, f4, f6
 */