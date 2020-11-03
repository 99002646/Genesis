#include<thread>
#include<iostream>
#include<chrono>
#include <functional>

constexpr int max=100;
std::chrono::milliseconds delay(1000);
//std::chrono::duration<int,std::milli> delay(1000);

void print_range(int start,int end) {
  std::cout << "printing range from:" << start << "to:" << end << "\n";
  for(int i=start;i<=end;i++) {
    std::cout << i << "\n";
    std::this_thread::sleep_for(delay);
  }
}
int main() {
  std::cout << "Main -- Welcome\n";
  int start,end,i;
  int n=10;
  std::thread tarr[n];//default ctor
  for(int i=0;i<n;i++) {
    start = i*10+1;
    end = start+10;
    tarr[i] = std::thread(print_range,start,end);
    //tarr[i]=std::thread(std::bind(print_range,start,end));
    //tarr[i]=std::thread([](){
    //   print_range(start,end);
    //});
  }
  for(i=0;i<n;i++)
    tarr[i].join();
  return 0;
}
/*
    std::thread t1;     //default, no active thread/execution
    t1=std::thread(compute);    //now active