#include <algorithm>
#include <iostream>
#include <list>
bool isOdd(int n) { return n % 2 == 1; }
int main() {

  std::list<int> mylist{32, 24, 12, 45, 50};
  std::count_if(mylist.begin(), mylist.end(), [](int x) { 
      return x > 30;  
  });
  std::remove_if(mylist.begin(), mylist.end(),
                 [](int n) { return n % 2 == 1; 
  });
  int sum = 0;
  std::for_each(mylist.begin(), mylist.end(), [&sum](int x) { 
      sum += x; 
  });  
  /*compute(10, 20, [](int x,int y) {
      return x + y;
  });*/
  compute(10, 20, sum);
}
int compute(int a, int b, int(*fcomp) (int,int) ) {
  int c;
  c = fcomp(a, b);
  return c;
}
int mycountif(auto start, auto end, auto fcompare) {
    int k=0;
    for(auto iter = start;iter!=end;++iter)
        if(fcompare(*iter)) k++;
    return k;
}
