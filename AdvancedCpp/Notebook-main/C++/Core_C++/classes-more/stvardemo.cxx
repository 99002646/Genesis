#include<iostream>
class Sample {
  int x;
  int y;

public:
  static int k;  //no memory at this point, decl only
  // declaration
  Sample(int p, int q) : x(p), y(q) { }
  // functions – printx, printy etc.
};

int Sample::k = 0; // definition, explicit

int main() {
  // print Sample::k
  Sample s1(10, 20);
  Sample s2(11, 21);
  Sample s3(12, 22);
  s1.k = 100;
  s2.k = 200;
  std::cout << s1.k << "," << s2.k << "," << s3.k << "\n";
  std::cout << Sample::k << "\n";
  Sample::k = 250;
  std::cout << Sample::k << "\n";
  return 0;
}
