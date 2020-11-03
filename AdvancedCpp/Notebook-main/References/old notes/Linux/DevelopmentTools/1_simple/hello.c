#include<stdio.h>

#define PI 22.0/7.0
#define SQUARE(x) (x) * (x)

int main() {
  int i=0;
  printf("Hello World\n");   /*some comment */
  printf("Thank You\n");
  double area, rad=7.0;
  area = PI * SQUARE(rad);
  /* Some comment*/
  printf("area=%f\n",area);
  return 0;
}
