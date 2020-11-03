#include<iostream>

int main() {
  int *parr, len = 10;
  parr = new int[len];
  for (int i = 0; i < len; i++)
    parr[i] = std::rand() % 100;
  //parr[15] = 150;                                  //@2
  for (int i = 0; i < len; i++)
    std::cout << parr[i] << "\n";

  delete parr;    
  //delete parr; //free parr;                       //@3
  //++parr;
  //delete[] parr;                                  //@4
  
  //parr[5] = 50;                                   //@1
  
  //delete[] parr;

  return 0;
}
/** valgrind usage to detect
* Memory leaks
* Read/write after free/delete
* Read/write beyond heap block size
* Mismatch between malloc/new/new[] and free/delete/delete[]
* Invalid/modified base address to delete
*/
