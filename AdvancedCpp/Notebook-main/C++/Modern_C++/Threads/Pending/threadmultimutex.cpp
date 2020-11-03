#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
 constexpr int maxv=10;
 std:: mutex mtx;
 std::chrono::milliseconds delay (1000);
void fsample()
{ 
   mtx.lock();
    for(int i=1;i<=maxv;i++)
    {
    std::cout<<"thread a"<<"\n";
    std::this_thread::sleep_for(delay);
    }
      mtx.unlock();
}
void gsample()
{
    mtx.lock();
    for(int i=1;i<=maxv;i++)
    {
    std::cout<<"thread b"<<"\n";
std::this_thread::sleep_for(delay);
    }
     mtx.unlock();
}

int main()
{ std::cout<<" welcome"<<"\n";
    std::thread t1(fsample);
    std::thread t2(gsample);
   
    t1.join();
    t2.join();
   
    std::cout<<"thank you";

    return 0;
}