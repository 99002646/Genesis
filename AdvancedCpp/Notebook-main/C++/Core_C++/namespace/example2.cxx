#include "abc.h"
#include "xyz.h"

/* Method-2
using n1::Sample;
using n2::test;
using n1::xvar;
using n2::zvar;
*/

/* Method-3
using namespace n1;
using namespace n2;
*/
#include<iostream>
int main() {
  /* Method-1  */
  n1::Sample s1;
  n1::test();
  std::cout << n1::xvar << "\n";
  ++n1::yvar;

  n2::Simple s2;
  n2::test();
  std::cout << n2::xvar << "\n";
  ++n2::zvar;
  return 0;
}
