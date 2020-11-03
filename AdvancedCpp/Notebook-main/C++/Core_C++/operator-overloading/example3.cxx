#include<iostream>
class MyTime {
  int hh;
  int mm;

public:
  MyTime():hh(0),mm(0) { }
  MyTime(int h, int m) : hh(h), mm(m) {}
  MyTime(const MyTime &ref) : hh(ref.hh), mm(ref.mm) {}
  bool operator==(const MyTime &ref) {
   return hh == ref.hh && mm == ref.mm;
  }
  bool operator< (const MyTime &ref) {
   //TODO : your logic here
  }
  bool operator> (const MyTime &ref) {
   //TODO : your logic here
  }
  void display() const { std::cout << hh << ":" << mm << "\n"; }

};
int main() {
  MyTime t1(10,20);
  MyTime t2(1,15);
  MyTime t3(10,20);
  //if(t1==t2)
  //if(t1<t2)
  //if(t1>t2)
  return 0;
}
