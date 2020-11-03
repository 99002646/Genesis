#include<iostream>
class MyTime {
  int hh;
  int mm;

public:
  MyTime():hh(0),mm(0) { }
  MyTime(int h, int m) : hh(h), mm(m) {}
  MyTime(const MyTime &ref) : hh(ref.hh), mm(ref.mm) {}
  MyTime operator+(const MyTime &ref) {
    int tmins = mm + ref.mm;  //TODO:tmins > 60
    int thrs = hh + ref.hh; 
    // MyTime tmp(thhrs, tmins);
    //return tmp;
    return MyTime(thrs, tmins);
  }
  MyTime operator+(int nmins) {
    int tmins = mm + nmins; // TODO: tmins > 60
    int thrs = hh;           
    return MyTime(thrs, tmins);
  }
  void display() const { std::cout << hh << ":" << mm << "\n"; }

};
int main() {
  MyTime t1(10,20);
  MyTime t2(1,15);
  MyTime t3;
  t3 = t1 + t2;    // t1.operator+(t2)
  t3.display();

  MyTime t4;
  t4 = t1 + 50;    //t1.operator+(50)
  t4.display();
  return 0;
}
