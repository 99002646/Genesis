#include<stdio.h>

/**
 * Functions returning reference
 * l-value context of such functions
 */

int& maxval(int& r1,int& r2) {
  if(r1 > r2)
    return r1;
  else
    return r2;
}
int& maxval(int* p1,int* p2) {
  if(*p1 > *p2)
    return *p1;
  else
    return *p2;
}
int main() {
  int a=10, b=20, c;
  c=maxval(a,b);
  c=maxval(&a,&b);

  maxval(a,b)++;            //l-value context of function
  maxval(a,b)=25;           //returning reference

  return 0;
}
/**
 std::vector<int>  v1;
 v1.at(5)=50;
 v1[6]=65;
*/


