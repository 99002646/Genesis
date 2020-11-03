#include <iostream>
int sum(int, int);
int *fetchp(void);
int &fetchr(void);

int main() {
  int a = 10, b = 20, c;
  c = sum(a, b);
  // print c

  int *ptr = fetchp();
  // do something
  std::cout << *ptr << "\n";

  int &ref = fetchr();
  // do something
  std::cout << ref << "\n";

  return 0;
}
int* fetchp(void) {
  int val = 100;
  return &val;
}
int& fetchr(void) {
  int val = 100;
  return val;
}

int sum(int x, int y) {
  int z;
  z = x + y;
  return z;
}

/** 
* Never return address/reference to local variables (or any thing on stack frame) 
* Violation from coding standards
* Reporting from cppcheck/clang-tidy
*/




