//USING Lambda functions in the Threads (t3) and using delay CHRONO

#include<iostream>
#include<thread>
#include<chrono>

constexpr int max=10;

std::chrono::milliseconds delay(1000);

//std::chrono::duration<int,std::milli> delay(1000);


void fcompute()
{
    std::cout<<"Thread -- A"<<std::endl;
    for(int i=1;i<=max;i++)
    {
        std::cout<<"A--"<<i<<std::endl;
        std::this_thread::sleep_for(delay);
        //this_thread <==> always represents the current thread
    }
}
void gcompute()
{
    std::cout<<"Thread -- B"<<std::endl;
    for(int i=1;i<=max;i++)
    {
        std::cout<<"B--"<<i<<std::endl;
        std::this_thread::sleep_for(delay);
    }
    
}
int main()
{
    std::cout<<"Main--welcome"<<std::endl;
    std::thread t1(fcompute);
    std::thread t2(gcompute);

    std::thread t3([](){ 
                            std::cout <<"thread --c"<<std::endl;
                            for(int i=1;i<=max;i++)
                            {
                                std::cout<<"C--"<<i<<std::endl;
                                std::this_thread::sleep_for(delay);
                            }
                        });
    t1.join();
    t2.join();
    t3.join();
    std::cout<<"Thank you"<<std::endl;
    return 0;
}