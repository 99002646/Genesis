#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
std:: atomic<int> val;
using namespace std;
constexpr int maxv=10000;
int val=100;
void fsample()
{
    std::cout<<"thread a"<<"\n";
    for(int i=1;i<=maxv;i++)

    val++;
     
}
void gsample()
{
     std::cout<<"thread b"<<"\n";
     
    for(int i=1;i<=maxv;i++)
   
      val--;
    
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