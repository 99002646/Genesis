#include <iostream>

int main() {
  int x = 100, y, val;

  int *iptr=&x;
  *iptr=200;
  val=*iptr;

  const int *pc = &x;           //pointer to const, *pc is read-only 
  *pc = 200; // error
  ++(*pc);   // error
  pc = &y;     // ok
  ++pc;        // ok
  ++x;         //ok
  ++*ptr;      //ok

  int ival = 100;
  int &ref=ival;
  const int &rc = ival; // reference to const
  //rc = 200;           // error
  //++(rc);             // error
  val = rc;

  const int cval = 100;
  int *ptr;
  //ptr = &cval;        // error
  //ptr = pc;           // error
  //int &ref = cval;    // error
  //int& ref = rc;      // error

  ptr = const_cast<int*>(&cval);
  int &ref = const_cast<int&> cval;

  const int *ptrc = &cval;
  const int &refc = cval;

  //TODO: usage of reinterpret_cast

  return 0;
}
