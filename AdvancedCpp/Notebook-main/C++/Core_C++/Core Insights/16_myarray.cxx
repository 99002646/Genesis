#include <cstdlib>
#include <iostream>
class MyArray {
  int *m_arr;
  int m_len;

public:
  MyArray() : m_arr(nullptr), m_len(0) {}
  MyArray(int len) : m_len(len) {
    m_arr = new int[m_len];
    /* for (int i = 0; i < len; i++)
         m_arr[i] = std::rand()%100; */
  }
  ~MyArray() {
    if (m_arr != nullptr)
      delete[] m_arr;
  }
  // TODO: copy ctor
  // TODO: operator=
  int &operator[](int index) { return m_arr[index]; }
  int &operator*() { return *m_arr; }
};
int main() {
  MyArray a1(10);
  a1[5] = 100;                //a1.operator[](5)
  std::cout << a1[5] << "\n";
  std::cout << *a1 << "\n";   //a1.operator*()
  return 0;
}