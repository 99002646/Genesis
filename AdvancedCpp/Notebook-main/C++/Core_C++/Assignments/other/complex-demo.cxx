//TODO: implement Complex class using templates, with operator overloading

int main() {
  Complex<int> c1(2,3);
  Complex<int> c2(1,2);
  Complex<int> res;
  std::cout << c1 << "," << c2  << "\n";
  res = c1 + c2;
  //print res
  res = c1 - c2;
  //print res
  res = c1 * c2;
  //print res
  Complex<int> c3(c1);
  if(c1==c3) 
     std::cout << "equal\n";
  Complex<int> c4(5);
  return 0;
}
  
