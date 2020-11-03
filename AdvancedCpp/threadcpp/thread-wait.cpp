#include<iostream>
#include<thread>
using namespace std;
 constexpr int maxv=10;
 std::chrono::milliseconds delay (1000);
void fsample()
{
    for(int i=1;i<=maxv;i++)
    {
    std::cout<<"thread a"<<"\n";
    std::this_thread::sleep_for(delay);}
}
void gsample()
{
    for(int i=1;i<=maxv;i++)
    {
    std::cout<<"thread b"<<"\n";
std::this_thread::sleep_for(delay);
    }
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