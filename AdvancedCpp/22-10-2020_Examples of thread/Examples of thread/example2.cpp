
//using for loops
#include<iostream>
#include<thread>
constexpr int max=100;
void fcompute()
{
    std::cout<<"Thread -- A"<<std::endl;
    for(int i=1;i<=max;i++)
        std::cout<<"A--"<<i<<std::endl;
}
void gcompute()
{
    std::cout<<"Thread -- B"<<std::endl;
    for(int i=1;i<=max;i++)
        std::cout<<"B--"<<i<<std::endl;
    
}
int main()
{
    std::cout<<"Main--welcome"<<std::endl;
    std::thread t1(fcompute);
    std::thread t2(gcompute);
    t1.join();
    t2.join();
    std::cout<<"Thank you"<<std::endl;
    return 0;
}