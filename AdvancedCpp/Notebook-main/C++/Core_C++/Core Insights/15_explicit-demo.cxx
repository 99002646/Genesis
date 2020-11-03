#include<iostream>
class MyTime {
  int hh;
  int mm;

public:
  MyTime():hh(0),mm(0) { }
  MyTime(int h, int m) : hh(h), mm(m) {}
  explicit MyTime(int tmins) : hh(tmins/60), mm(tmins%60) {}
  //explicit MyTime(int tmins) : hh(tmins/60), mm(tmins%60) {}
  explicit MyTime(const MyTime &ref) : hh(ref.hh), mm(ref.mm) {}
  void display() const { std::cout << hh << ":" << mm << "\n"; }

};
int main() {
  MyTime t1(10,20);
  MyTime t2(1,15);

  MyTime t3(400);    //6:40
  //MyTime t4 = 250;   //4:10

  MyTime t5;
  //t5 = 200;          //t5 = MyTime(200);

  MyTime t6(t1);
  //MyTime t7 = t1;
 
  return 0;
}
