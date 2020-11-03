#include<iostream>
#include<thread>
#include<mutex>
std:: mutex mtx1;
std::mutex mtx2;
using namespace std;
constexpr int maxv=100;
int val=0,val1=0;
void fsample()
{
    std::cout<<"thread a"<<"\n";
    for(int i=1;i<=maxv;i++)
     {
         mtx1.lock();
       
       val++;
      
       std::chrono::milliseconds delay (1000);
        std::cout<<val<<"\n";
        mtx1.unlock();

       }
    
       
}
void gsample()
{
     std::cout<<"thread b"<<"\n";
     
    for(int i=1;i<=maxv;i++)
    {
    mtx2.lock();
      val1++;
     
      std::chrono::milliseconds delay (1000);
       std::cout<<val<<"\n";
       mtx2.unlock();
     }
    
}

int main()
{ std::cout<<" welcome"<<"\n";
    std::thread t1(fsample);
    std::thread t2(gsample);
    t1.join();
    t2.join();
    std::cout<<val<<"\n"<<val1<<"\n";

    return 0;
}