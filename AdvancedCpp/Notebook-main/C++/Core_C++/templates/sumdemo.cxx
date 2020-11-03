/*
#include<complex>
typedef std::complex<int> complex;
int sum(int x, int y) { return x + y; }
float sum(float x, float y) { return x + y; }
double sum(double x, double y) { return x + y; }
complex sum(complex &r1, complex &r2) { return r1 + r2; }
int main() {
    int a, b, c;
    float x, y, z;
    //sum(a,y);

}
*/
#include<iostream>
template<typename T>
T sum(T x , T y) {
  T res;
  res = x + y;
  return res;
}

int main() {
  int a, b, c;
  float x, y, z;
  double p, q, r;
  char c1, c2;
  
  c = sum(a, b);    //T: int
  y = sum(x, y);    //T: float
  r = sum(p, q);    //T: double
  
  //sum(a,x);
  //sum(p,b);
  
  sum<int>(a,x);    //int
  sum<double>(p,b); //double

  sum<int>(c1,c2);
  // 3 instantiations
  
  return 0;
}
