#include "fun.h"
#include <stdio.h>
int main() {
  int a, b, c, d,MACRO;
  a = 10;
  b = 20;
  MACRO = 30;
  c = sum(a, b);
  d = square(a);
  //prod(c,d);
  printf("c=%d,d=%d, %d\n",c,d, MACRO);
  return 0;
}