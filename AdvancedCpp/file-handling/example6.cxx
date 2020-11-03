#include <iomanip>
#include <iostream>
int main() {
  int x = 235;
  double y = 2.3457812345;
  std::cout << std::setw(6) << std::setfill('#') << x << "\n";
  std::cout << std::setprecision(3) << y << "\n";
  // std::cout << std::resetiosflags(std::ios_base::dec);
  std::cout << std::setiosflags(std::ios::hex | std::ios::showbase) << 200 << "\n";
  std::cout << std::setbase(8) << 64 << "\n";
  return 0;
}
