/* __Example 1__Basis Threads with Lambda
g++ exp1b.cpp -lpthread && ./a.out
*/



#include <iostream>
#include <thread>

#define print(msg) std::cout << msg << std::endl

void fsample(){
    print("Thread A"); 
}

void gcompute(){
    print("Thread B");
}


int main(){
    print("Main-- Welcome");
    std::thread t1(fsample);    // Created Thread1 for fsample
    std::thread t2(gcompute); // 2nd Parallel Thread
    std::thread t3([] (){std::cout<<"lambda function"<<"\n";});
    t1.join();      //Main Thread waits until t1 and t2 finishes
    t2.join(); 
    t3.join();  
    print("Thankyou");
    return 0;

}

/* Output

Main-- Welcome
Thread A
Thread B
lambda function
Thankyou

*/