#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>

void *operator new(size_t nbytes) {
  std::cout << "Global operator new\n";
  return malloc(nbytes); // return new
}
void *operator new(size_t nbytes, char ch) {
  void *ptr;
  ptr = malloc(nbytes);
  if (ptr != NULL)
    memcpy(ptr,&ch,nbytes);
  return ptr;
}
void *operator new[](size_t count, char ch) {
  void *ptr;
  ptr = malloc(count);
  if (ptr != NULL)
    memcpy(ptr,&ch,count);
  return ptr;
}
void operator delete(void *pbase) {
  std::cout << "Global operator delete\n";
  free(pbase); // delete pbase
}
class Sample {
  int x;

public:
  Sample() : x(0) {}
  Sample(int p) : x(p) {}
  void *operator new(size_t nbytes) {
    std::cout << "Sample::operator new\n";
    void *pbase = ::new Sample();
    return pbase;
  }
  void operator delete(void *pbase) {
    std::cout << "Sample::operator delete\n";
    ::delete (Sample*)pbase;  //free(pbase);
  }
};
int main() {
  Sample *ps = new Sample(10);
  delete ps;
  int *parr = new int[10];
  delete[] parr;
  char *pc = new('#') char;
  delete pc;
  char *pbuf = new('#') char[32];
  delete[] pbuf;
  return 0;
}