/**
 * Return Value Optimization(RVO)
 * Named Return Value Optimization(NRVO)
 * Copy elison followed by compiler
 * Disable elison with -fno-elide-constructors
 */
#include <iostream>
class Sample {
  int x;
  //char buf[100];

public:
  Sample():x(0) {}
  Sample(int p) : x(p) {
    std::cout << "Sample::Sample(int)"
              << "\n";
  }
  Sample(const Sample &ref) : x(ref.x) {
    std::cout << "Sample::Sample(const Sample&)" << "\n";
  }
  Sample &operator=(const Sample &ref) {
    x = ref.x;
    std::cout << "Sample::operator=(const Sample&)" << "\n";
  }
  void display() const { std::cout << x << "\n"; }
  int getx() const { return x; }
};

//c = sum(a,b);       //z --> cpu reg, cpu reg --> c
                      //typically accumulator

int sum(int x,int y) {    //Activation Record/Stack Frame
  int z;
  z = x + y;
  return z;
}

Sample fetch(int x) {
  //some logic 
  //Sample tmp(x);
  //return tmp;
  return Sample(x); 
}  
//Returned object will be copied a temp object (in reserved space)
//and that temp object will be assigned to dest/res

int main() {
  Sample s1 = fetch(100);   
  //Sample s2 = 200;   //Sample s2 = Sample(200);
  //Sample s3;
  //s3 = 150;          // s3 = Sample(150);
  //Sample s4 = s3;
  return 0;
}