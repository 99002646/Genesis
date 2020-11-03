#include <iostream>
class MyTime
{
  int hh;
  int mm;

public:
  MyTime(int h, int m) : hh(h), mm(m) {}
  MyTime(const MyTime &ref) : hh(ref.hh),
                              mm(ref.mm) {}
  friend std::ostream &operator<<(std::ostream &rout,
                             const MyTime &ref);
  friend std::istream& operator>>(std::istream &rin, MyTime &ref);                            
};
std::ostream& operator<<(std::ostream &rout, const MyTime &ref)
{
  rout << ref.hh << ":" << ref.mm << "\n";
  return rout;
}
std::istream& operator>>(std::istream &rin, MyTime &ref)
{
  rin >> ref.hh >> ref.mm;
  return rin;
}
int main() {
  MyTime t1(10, 20);
  std::cout << t1 << "\n";  // std::cout.operator<<(t1), operator<<(std::cout, t1)
  std::cin >> t1;

  int x;
  std::cout << x ;   // std::cout.operator<<(x), operator<<(std::cout, x)

  return 0;
}
