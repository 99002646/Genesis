#include<thread>
#include<iostream>
#include<chrono>
#include <functional>

constexpr int max=100;
std::chrono::milliseconds delay(1000);
//std::chrono::duration<int,std::milli> delay(1000);

void compute(std::string label){
    std::cout<<"Thread--"<<label<<"\n";
    for(int i=1;i<=max;i++){
        std::cout<<label<<"--"<<i<<"\n";
        std::this_thread::sleep_for(delay);
    }
}
/*
void gcompute(){
    std::cout<<"Thread--B\n";
    for(int i=1;i<=max;i++)
        std::cout<<"B--"<<i<<"\n";
        std::this_thread::sleep_for(delay);
}
*/
int main(){
    std::cout<<"Main--Welcome\n";
    std::thread t1(std::bind(compute,"A"));
   // std::thread t2(std::bind(compute,"B"));
   std::thread t2(compute,"B");
   std::thread t3([](){
       compute("C");
   });
    t1.join();
    t2.join();
    std::cout<<"Thank You\n";
    return 0;
}