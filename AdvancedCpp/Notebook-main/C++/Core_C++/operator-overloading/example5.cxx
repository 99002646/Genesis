#include<iostream>
class MyTime {
  int hh;
  int mm;

public:
  MyTime():hh(0),mm(0) { }
  MyTime(int hh, int mm) : hh(hh), mm(mm) {}
  MyTime(const MyTime &ref) : hh(ref.hh), mm(ref.mm) {}

  friend MyTime operator+(const MyTime &r1, const MyTime &r2);
  friend MyTime operator+(const MyTime &r1, int);
  friend MyTime& operator++(MyTime &r1);
  friend MyTime operator++(MyTime &r1,int);
  friend bool operator==(const MyTime &r1, const MyTime &r2);
  friend bool operator<(const MyTime &r1, const MyTime &r2);
};
MyTime operator+(const MyTime &r1, const MyTime &r2) {   // t1 + t2
  int th = r1.hh + r2.hh;
  int tm = r1.mm + r2.mm;
  return MyTime(th,tm);
}
MyTime operator+(const MyTime &r1, int nm) {   // t1 + 5
  int th = r1.hh;
  int tm = r1.mm + nm;
  return MyTime(th,tm);
}
MyTime& operator++(MyTime &r1) {    // ++t1
  ++r1.mm;
  return r1;
}
MyTime operator++(MyTime &r1,int dummy) { //t1++   
  MyTime orig(r1);
  ++r1.mm;
  return orig;
}
bool operator==(const MyTime &r1, const MyTime &r2) {  // t1 == t2
  return r1.hh == r2.hh && r1.mm == r2.mm;
}
bool operator<(const MyTime &r1, const MyTime &r2) {  // t1 == t2
  //TODO
}
int main() {
  MyTime t1(10, 20);
  MyTime t2(1, 15);
  MyTime t3, t4, t5, t6;
  t3 = t1 + t2;    // operator+(t1, t2)
  t4 = t1 + 50;    // operator+(t1, 50)
  t5 = ++t1;       // operator++(t1)
  t6 = t1++;       // operator++(t1,int)
  if (t5 == t6)    // operator==(t5, t6)
    std::cout << "Equal\n";
  else
    std::cout << "Not Equal\n";  
}
