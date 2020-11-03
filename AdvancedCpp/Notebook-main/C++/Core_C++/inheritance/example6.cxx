class A {
  int x;
public:
  void f1();

private:
  void f2();

protected:
  void f3();
};
class B : public A {};
class C : public B {
  public:
  void f4() { 
    //f2();
    f3();  
  }
};
class D {
  A at;
  public:
  void test() {
    at.f1();
    //at.f2();
    //at.f3();
  }
};
void gdemo(A& ref) {
  ref.f1();
  //ref.f2();
  //ref.f3();
}
int main() {
  A a1;
  a1.f1();
  //a1.f2();
  //a1.f3();
  C c1;
  //c1.f3();
  gdemo(a1);
  return 0;
}
