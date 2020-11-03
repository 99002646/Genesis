// DATA DRIVEN EXAMPLE -4 (one fucntion different data)
// TASK DRIVEN EXAMPLE 1,2,3
//USING std::bind()

#include<iostream>
#include<thread>
#include<chrono>
#include<functional>
constexpr int max=10;

std::chrono::milliseconds delay(1000);

//std::chrono::duration<int,std::milli> delay(1000);


void compute(std::string label)
{
    std::cout<<"Thread -- "<<label<<std::endl;
    for(int i=1;i<=max;i++)
    {
        std::cout<<label<<"--"<<i<<std::endl;
        std::this_thread::sleep_for(delay);
        //this_thread <==> always represents the current thread
    }
}
  

int main()
{
    std::cout<<"Main--welcome"<<std::endl;
    std::thread t1(std::bind(compute,"A"));     //1st method -> std::bind()
    //std::thread t2(std::bind(compute,"B"));
    std::thread t2(compute,"B");                //2nd method -> function name and arg
    std::thread t3([](){compute("c");});        //3rd method -> using lambda (alternative of bind)

    t1.join();
    t2.join();
    t3.join();
    std::cout<<"Thank you"<<std::endl;
    return 0;
}