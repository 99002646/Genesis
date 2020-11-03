#include<iostream>
#include<fstream>
class MyTime {
  int hh;
  int mm;

public:
  // constructors
  friend std::ostream &operator<<(std::ostream &,const MyTime &ref);
  friend std::istream &operator>>(std::istream &,MyTime &ref);
};
// Definitions of operator<<, operator>>
int main() {
  std::ofstream tout("out.txt");
  std::ifstream tin("in.txt");
  MyTime t1(10, 12);
  tout << t1;
  MyTime t2;
  tin >> t2; // assuming suitable
  // delimiter in the input file
  tout.close();
  tin.close();
  return 0;
}
