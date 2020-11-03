#include<iostream>

int main() {

  /*int *ptr;
  ptr=new int; // new int(100)
  *ptr=100;
  std::cout << *ptr << "\n";
  delete ptr;*/

  int *parr, len = 10;
  parr = new int[len];
  for (int i = 0; i < len; i++)
    parr[i] = std::rand() % 100;
  for (int i = 0; i < len; i++)
    std::cout << parr[i] << "\n";
  delete[] parr;
  parr = NULL;
  return 0;
}

/** new vs malloc
 * strongly typed, no void*
 * new is an operator
 * can invoke constructor
 */