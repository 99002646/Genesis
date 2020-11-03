//Simple example of creating threads in c++

#include<iostream>
#include<thread>
void fcompute()
{
    std::cout<<"Thread -- A"<<std::endl;

}
void gcompute()
{
    std::cout<<"Thread -- B"<<std::endl;
    
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