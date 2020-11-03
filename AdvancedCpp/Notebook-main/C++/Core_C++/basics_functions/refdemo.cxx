#include <iostream>

int main() {
  int x = 10;
  int &ref = x;
  ref = 20;
  std::cout << x << "\n";
  ++x;
  std::cout << ref << "\n";
  std::cout << &x << "," << &ref << "\n";

  //float& rf=x;
}

/** Reference variables
 * Real usage - fetch the result - pass by reference
 * efficiently pass the objects
 * /