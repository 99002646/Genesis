#include<iostream>
#include<thread>
#include<functional>
using namespace std;
 constexpr int maxv=10;
 std::chrono::milliseconds delay (1000);
void fsample(std::string label)
{
    for(int i=1;i<=maxv;i++)
    {
    std::cout<<"thread "<<label<<"\n";
    std::this_thread::sleep_for(delay);}
}


int main()
{ std::cout<<" welcome"<<"\n";
    std::thread t1(std::bind(fsample,"A"));
    std::thread t2(std::bind(fsample,"B"));
   
    t1.join();
    t2.join();
   
    std::cout<<"thank you";

    return 0;
}