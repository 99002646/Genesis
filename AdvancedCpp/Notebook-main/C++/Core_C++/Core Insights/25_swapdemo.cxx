#include<iostream>
template<typename T>
void myswap(T* p1, T *p2) {
  std::cout << "myswap(T*,T*)"  ;
  T temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

template<typename T>
void myswap(T& r1, T& r2) { 
  std::cout << "myswap(T&,T&)"  ;
  T temp = r1;
  r1 = r2;
  r2 = temp;
}

int main() {
  int a=10, b=20;
  float x=2.3f, y=5.6f;
  double p=2.3, q=5.6;
  myswap(&a, &b);
  myswap(&x, &y);
  myswap(&p, &q);
  
  myswap(a, b);
  myswap(x, y);
  myswap(p, q);
  
  int *p1=&a, *p2=&b;
  myswap(p1, p2);  //??
  //myswap(10,20);   //??
  //myswap(a+b, 5);  //??
  
  return 0;
}
