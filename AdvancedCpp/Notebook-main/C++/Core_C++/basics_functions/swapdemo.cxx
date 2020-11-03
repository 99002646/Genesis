#include <iostream>
void tryswap(int, int);
void myswap(int *, int *);
void myswap(int &, int &);

int main() {
  int a = 10, b = 20;
  tryswap(a, b);
  std::cout << a << "," << b << "\n";

  myswap(&a, &b);
  std::cout << a << "," << b << "\n";

  myswap(a, b);
  std::cout << a << "," << b << "\n";

  return 0;
}
void myswap(int &r1, int &r2) {
  int temp = r1;
  r1 = r2;
  r2 = temp;
}
void myswap(int *p1, int *p2) {
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void tryswap(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}
void test(const int& ref) {
  //print ref
}
