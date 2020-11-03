#include <iostream>
class A {
  int x;

public:
  A(int p) : x(p) {}
  void printx() const { std::cout << x << "\n"; }
  int getx() const { return x; }
};
class B {
  A a1;
  int y;

public:
  /*B(int p,int q) {    //no default ctor for class A
    a1 = p;           //operator=
    y = q;
  }*/
  /*B(const B& ref) {   //default
    a1 = ref.a1;      //operator=
    y = ref.y;
  }*/
  B(int p, int q) : a1(p), y(q) {}            //params
  B(const B& ref) : a1(ref.a1), y(ref.y) { }  //copy
  void printxy() const {
    a1.printx();
    std::cout << y << "\n";
  }
};
int main() {
  B b1(10, 20);
  return 0;
}
/** TODO:-
 * Engine class part of Vehicle
 * In Employee class, name as MyString type instead of std::string
 */