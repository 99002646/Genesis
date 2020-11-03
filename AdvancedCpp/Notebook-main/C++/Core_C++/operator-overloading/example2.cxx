#include<iostream>
class MyTime {
  int hh;
  int mm;

public:
  MyTime():hh(0),mm(0) { }
  MyTime(int h, int m) : hh(h), mm(m) {}
  MyTime(const MyTime &ref) : hh(ref.hh), mm(ref.mm) {}
  MyTime& operator++() {
    ++mm; // TODO: mm > 60
    return *this;
  }
  MyTime operator++(int dummy) {
    MyTime orig(*this);
    ++mm; // TODO: mm > 60
    return orig;
  }
  void display() const { std::cout << hh << ":" << mm << "\n"; }

};
int main() {
  MyTime t1(10,20);
  MyTime t2(1,15);
  
  ++t1; 
  (++t2).display();  
  // ++t1 + t2

  MyTime t3(5,40);
  MyTime t4;
  t4 = t3++;      //t3.operator++(int)
  // (t3++).display()
  // t1 + t3++

  return 0;
}
