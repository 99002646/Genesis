#include <iostream>

int sum(int, int);
int sum(int, int, int);
float sum(float, float);    //function overloading

int main() {
  int a = 10, b = 20, c = 30;
  float x = 2.3f, y = 5.6f, z = 8.2f;
  double p = 2.3, q = 5.6, r = 8.2;
  char c1 = 'A', c2 = 32;

  sum(a, b);
  sum(x, y);
  sum(a, b, c);

  sum(x, y, z);     
  sum(p, q, r);   
  sum(c1, c2);

  // sum(p,q);
  // sum(a,x);
  // sum(x,b);

  // sum(&a,&b);
  // sum(a,b,x,y);
  return 0;
}
int sum(int x, int y) { return x + y; }
int sum(int x, int y, int z) { return x + y + z; }
float sum(float x, float y) { return x + y; }

/* Resolve overloading
* idnetify all functions with same name as function call
* let's call them as candidate functions
* no candidate functions -- error
* exact match -- success
* if no exact match, try for near match with implicit conversions
    * exactly one near match -- success
    * no near match -- failure
    * multiple near matchess -- failure (ambiguous)

* compile time polymorphism, static/early binding
* how C++ supports overloading, but not in C
* Name magling/demangling in C++
*/