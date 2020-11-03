#include <iostream>

int main() {
  int x = 100, y;
  const int *pc = &x;
  //*pc = 200; // error
  //++(*pc);   // error
  pc = &y;     // ok
  ++pc;        // ok

  int ival = 100;
  const int &rc = ival; // reference to const
  //rc = 200;           // error
  //++(rc);             // error

  const int cval = 100;
  int *ptr;
  //ptr = &cval;        // error
  //int &ref = cval;    // error
  const int *ptrc = &cval;
  const int &refc = cval;

  return 0;
}