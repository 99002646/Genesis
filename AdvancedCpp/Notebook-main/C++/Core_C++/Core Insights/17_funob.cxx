/* Function Objects */

#include<iostream>
class Adder {
   public:
   int operator()(int x,int y) { return x + y; }
   int operator()(int x,int y,int z) { return x + y + z; }
   float operator()(float x,float y) { return x + y; }
};
int main() {
    Adder sum;
    std::cout << sum(10,20) << "\n";
    std::cout << sum(10,20,18) << "\n";
    std::cout << sum(2.3f,4.5f) << "\n";
    return 0;
}
//sum(10,20)    ==> sum.operator()(10,20)