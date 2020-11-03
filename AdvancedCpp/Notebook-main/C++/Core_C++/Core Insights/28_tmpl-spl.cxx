#include <iostream>

template <typename T> void myswap(T p1, T p2) { std::cout << "myswap(T,T)\n"; }
template <typename T> void myswap(T *p1, T *p2) {
  std::cout << "myswap(T*,T*)\n";
}
template <> void myswap<char>(char *p1, char *p2) {
  std::cout << "myswap(char*,char*)\n";
}

template <typename T> class Sample {
public:
  Sample() { std::cout << "Sample<T>, not specialized\n"; }
};

template <> class Sample<char> {
public:
  Sample() { std::cout << "Sample<char> specialized\n"; }
};

int main() {
  char *ps1, *ps2;
  myswap<char>(ps1, ps2);
  // myswap<char>(ps1, ps2);
  int x, y;
  myswap(&x, &y);

  Sample<int> s1;
  Sample<char> s2;
}