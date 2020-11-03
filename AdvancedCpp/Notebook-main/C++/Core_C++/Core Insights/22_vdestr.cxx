#include <iostream>
class A {
  int m_len;

public:
  A(int len) : m_len(len) {}
  virtual ~A() { std::cout << "A--destr\n"; }
  int length() const { return m_len; }
};
class B : public A {
  int *m_arr;

public:
  B(int len) : A(len) { m_arr = new int[len]; }
  ~B() { 
    std::cout << "B--destr\n";
    delete[] m_arr;
  }
};
int main() {
  A *ptr = new B(10);
  delete ptr;
  return 0;
}