#include <iostream>

int sum(int, int, int = 30);

int main() {
  int a = 10, b = 20, c = 18;
  int r1, r2;
  r1 = sum(a, b, c);
  r2 = sum(a, b);
  // print r1,r2
  return 0;
}
int sum(int x, int y, int z) { return x + y + z; }