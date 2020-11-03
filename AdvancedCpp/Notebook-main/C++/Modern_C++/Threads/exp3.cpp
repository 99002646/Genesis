//__Example3__ Basic with Delay

// g++ exp3.cpp -lpthread && ./a.out
#include <iostream>
#include <thread>
#include <chrono>
#include <string>  

constexpr int max =5;

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

std::chrono::milliseconds delay(1000);
//std::chrono::duration<int,std::milli> delay(1000);


void fsample(){
    print("Thread A"); 
    for(int i=0;i<=max;i++){
      print("A-" + str(i));   
      std::this_thread::sleep_for(delay);
    }
}

void gcompute(){
    print("Thread B");
    for(int i=max;i>=0;i--){
      print("B-" + str(i));   
      //std::this_thread::sleep_for(delay); 
    }
}

int main(){
    print("Main-- Welcome");
    std::thread t1(fsample);    // Created Thread1 for fsample
    std::thread t2(gcompute); // 2nd Parallel Thread
    t1.join();
    t2.join();
    print("Thankyou");
    return 0;

}

/* Output(3a)-Toggle Sleep for both Threads
Main-- Welcome
Thread A
A-0
Thread B
B-5
A-1
B-4
A-2
B-3
A-3
B-2
A-4
B-1
A-5
B-0
Thankyou

Output(3b)--No Sleep for Thread 2-B
Main-- Welcome
Thread A
A-0
Thread B
B-5
B-4
B-3
B-2
B-1
B-0
A-1
A-2
A-3
A-4
A-5
Thankyou



Observation :
* after line48 Thread1-a will be in sleep so cpu runs b thread 
* In 3b - Thread 2-b will be alloted Cpu when thread 1-a is in sleep
When Active Thread in CPU goes to sleep ,cpu allocated another thread to cpu

*/