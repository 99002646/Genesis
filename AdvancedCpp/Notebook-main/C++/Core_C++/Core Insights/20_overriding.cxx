class A {
public:
  void f1();
  void f2();
  void f3();
};
class B : public A {
public:
  void f2();
  void f3();
};
class C : public B {
public:
  void f3();
};
int main() {
  C c1;
  c1.f3();
  c1.f2();
  c1.f1();

  B b1;
  b1.f3();
  b1.f2();
  b1.f1();

  return 0;
}
