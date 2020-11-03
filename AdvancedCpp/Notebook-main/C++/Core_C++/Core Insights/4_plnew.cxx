#include<iostream>
//.data, .bss, .text, stack, heap, .rodata
int main() {
  char buf[100];  //char *buf=new buf[100];
  int *parr = new (buf) int[10];
  //Access elements using parr

  //??? should we use delete on parr, Ans:- No
  //delete[] buf;
  return 0;
}
/**
* placement new operator allocates object in pre existing/allocated memory
* i.e. no memory allocation, only initialization
* Should we call delete on pointer assigned with placement new operator
* Hint:- placement new operator is the basis for emplace operations introduced in C++11
*/
