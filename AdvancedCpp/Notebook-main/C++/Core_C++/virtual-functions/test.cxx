class A {
  int x;

public:
  A(int p):x(p) {}
  void show() { std::cout << "A--show\n"; }
};
class B : public A {
  int y;
public:
  B(int p, int q):A(p),y(q) { }
  void show() { std::cout << "B--show\n"; }
};
int main() {
   A a1(10);
   B b1(11,12);

   A* p1,*p2;
   p1=&a1;
   p2=&b1;

   p1->show();
   p2->show();

   A& r1=a1;
   A& r2=b1;
   r1.show();
   r2.show();
  
   return 0;

}
