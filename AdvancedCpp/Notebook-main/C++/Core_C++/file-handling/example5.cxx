#include <iostream>
int main() {
  int x = 23;
  double y = 2.3457812345;
  std::cout.width(6);
  std::cout.fill('*');
  std::cout << x << "\n";
  std::cout.precision(4);
  std::cout << y << "\n";
  return 0;
}
