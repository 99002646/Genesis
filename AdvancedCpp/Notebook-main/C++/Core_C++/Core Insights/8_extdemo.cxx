#include "fun.h"

extern "C" {
  int sum(int x, int y) { return x + y; }
}

int main() {
  double p = 3.5, q;
  q = square(p);
  // print q
  return 0;
}

/**
 * How to link with square function defined in test.c
 * How the function call to sum in test.c can link with sum function defined here
*/
