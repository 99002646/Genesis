#include<iostream>
namespace n1 {
class Sample {
  // members
};
void test() {}
int xvar = 100;
int yvar = 200;
} // namespace abc

namespace n2 {
class Simple {
  // members
};
void test() {}
int xvar = 100;
int zvar = 300;
} // namespace xyz


/*Method-2 
using n1::Sample;
using n2::test;
using n1::xvar;
using n2::zvar;
using n2::Simple;

using n1::test;
*/


//Method-3
using namespace n1;
using namespace n2;

int main() {
  /* Method-1  */
  /*n1::Sample s1;
  n1::test();
  std::cout << n1::xvar << "\n";
  ++n1::yvar;

  n2::Simple s2;
  n2::test();
  std::cout << n2::xvar << "\n";
  ++n2::zvar;*/

  Sample s1;
  //test();     //from n2
  //++xvar;     //from n1
  --zvar;
  
  test();

  //n1::test();
  //++n2::xvar;
  Simple s2;


  return 0;
}

/* namespace std {
    ostream cout;
    class string {

    };
  }
*/