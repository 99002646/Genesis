#include <iostream>

/**
 * How C++ supports overloading, but not C (as object code format is same for both)
 * Name mangling in C++
 * Checking mangled names using nm command
 * Checking demangled names using -C option
*/

int sum(int, int);
int sum(int, int, int);
float sum(float, float);

int main() {
  int a = 10, b = 20, c = 30;
  float x = 2.3f, y = 5.6f, z = 8.2f;
  double p = 2.3, q = 5.6, r = 8.2;
  char c1 = 'A', c2 = 32;

  sum(a, b);
  sum(x, y);
  sum(a, b, c);

  sum(x, y, z);
  //sum(p,q);
  sum(p, q, r);
  sum(c1, c2);
  // sum(a,x);
  // sum(x,b);
  return 0;
}
int sum(int x, int y) { return x + y; }
int sum(int x, int y, int z) { return x + y + z; }
float sum(float x, float y) { return x + y; }