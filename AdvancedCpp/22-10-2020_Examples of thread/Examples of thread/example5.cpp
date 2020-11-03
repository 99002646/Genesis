// DATA DRIVEN EXAMPLE -4 (one fucntion different data)
// TASK DRIVEN EXAMPLE 1,2,3
//USING std::bind()

#include<iostream>
#include<thread>
#include<chrono>
#include<functional>
constexpr int max=10;

std::chrono::milliseconds delay(100);

//std::chrono::duration<int,std::milli> delay(1000);


void print_range(int start, int end)
{
    int i;
    std::cout<<"printing range from"<<start<<" to "<<end<<std::endl;
    for(i=start;i<=end;i++)
    {
        std::cout<<i<<std::endl;
        std::this_thread::sleep_for(delay);
        //this_thread <==> always represents the current thread
    }
}
  

int main()
{
    std::cout<<"Main--welcome"<<std::endl;

    
    int n=10,start,end,i;
    std::thread tarr[n];   //thread object is created using default constructor
    for(i=0;i<n;i++)
        start = i*10+1;
        end = start +10;
        tarr[i]=std::thread(print_range,start,end);                 
        //tarr[i]=std::thread(std::bind(print_range,start,end));    //2nd method
        //tarr[i]=std::thread([](){print_range(start,end)});        // 3rd method
    for(i=0;i<n;i++)
        tarr[i].join();
    std::cout<<"Thank you"<<std::endl;
    return 0;
}