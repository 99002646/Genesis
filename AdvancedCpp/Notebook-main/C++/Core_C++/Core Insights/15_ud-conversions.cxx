#include<iostream>
class MyTime {
  int hh;
  int mm;

public:
  MyTime():hh(0),mm(0) { }
  MyTime(int h, int m) : hh(h), mm(m) {}
  explicit MyTime(int tmins) : hh(tmins/60), mm(tmins%60) {}
  explicit MyTime(const MyTime &ref) : hh(ref.hh), mm(ref.mm) {}
  MyTime& operator=(int tmins) {
    hh = tmins/60;
    mm = tmins%60;
    return *this;
  }
  operator int() { return hh * 60 + mm; }
  void display() const { std::cout << hh << ":" << mm << "\n"; }

};
int main() {
  MyTime t1(10,20);
  MyTime t2(1,15);

  MyTime t3(400);
  //MyTime t4 = 250;   //error
  //MyTime t5 = t1;    //error

  MyTime t6;
  t6 = 200;          //with the help of operator=, 
                     //not thru ctor, t6.operator=(200)

  int nmins;
  nmins = t2;        //nmins = t2.operator int()
 
  return 0;
}
/** User defined type conversions
 * scalar (primitive) to user defined type and vice versa
 */
