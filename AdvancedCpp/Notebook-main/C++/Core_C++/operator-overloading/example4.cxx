#include<iostream>
class MyTime {
  int hh;
  int mm;

public:
  MyTime():hh(0),mm(0) { }
  MyTime(int h, int m) : hh(h), mm(m) {}
  MyTime(const MyTime &ref) : hh(ref.hh), mm(ref.mm) {}
  MyTime& operator=(const MyTime &ref) {
    if(this == &ref) return *this;  //self assignment check
    hh = ref.hh;
    mm = ref.mm;
    return *this;
  }

  MyTime& operator+=(const MyTime &ref) {
    hh += ref.hh;
    mm += ref.mm;  //TODO: mm > 60
    return *this;
  }
  void display() const { std::cout << hh << ":" << mm << "\n"; }

};
int main() {
  MyTime t1(10,20);
  MyTime t2;
  t2 = t1;          //t2.operator=(t1)
  t2.display();     //t3 = t2 = t1

  MyTime t3(1,10);
  t1 += t3;
  t3.display();
  return 0;
}
