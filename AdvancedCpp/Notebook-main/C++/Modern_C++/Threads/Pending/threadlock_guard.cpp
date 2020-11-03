#include<iostream>
#include<thread>
#include<mutex>
std:: mutex mtx;

using namespace std;
constexpr int maxv=10000;
int val=100;
void fsample()
{
    std::cout<<"thread a"<<"\n";
    const std::lock_guard<std::mutex> lock(mtx);
 
    for(int i=1;i<=maxv;i++)
    {
       val++;
    }
}
void gsample()
{
     std::cout<<"thread b"<<"\n";
     const std::lock_guard<std::mutex> lock(mtx);
    for(int i=1;i<=maxv;i++)
    {
      val--;
     }
}

int main()
{ std::cout<<" welcome"<<"\n";
    std::thread t1(fsample);
    std::thread t2(gsample);
    t1.join();
    t2.join();
    std::cout<<val;

    return 0;
}