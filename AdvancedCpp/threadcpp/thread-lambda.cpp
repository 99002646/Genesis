#include<iostream>
#include<thread>
using namespace std;
constexpr int maxv=100;
void fsample()
{
    for(int i=1;i<=maxv;i++)
    std::cout<<"thread a"<<"\n";

}
void gsample()
{
    for(int i=1;i<=maxv;i++)
    std::cout<<"thread b"<<"\n";

}

int main()
{ std::cout<<" welcome"<<"\n";
    std::thread t1(fsample);
    std::thread t2(gsample);
    std::thread t3([] (){ for(int i=1;i<=maxv;i++)std::cout<<"lambda function"<<"\n";});
    t1.join();
    t2.join();
    t3.join();
    std::cout<<"thank you";

    return 0;
}