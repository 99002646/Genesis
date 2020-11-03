/*Write a program to implement two threads, where output from both threads will 
   come,with switching after every 5 iterations*/

#include<bits/stdc++.h>
using namespace std;
constexpr int mmax = 50;

std::chrono::milliseconds delay(1000);
#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

std::mutex mut1;
std::condition_variable cv1,cv2;
bool t1_flag = true, t2_flag =false;    
int tcount=1;


void block1(){
  std::unique_lock<std::mutex> lck(mut1);
    while(tcount<mmax){
        cv2.wait(lck,[](){return t1_flag;});            
        if(tcount>mmax)                         
            break;
        print("-----------TA-----------");
        for(int i=tcount;i<=tcount+4;i++){
            print("A: "+ str(i));
        }
        tcount += 5;
        t2_flag=true;           
        cv1.notify_one();     
        t1_flag = false;       
   }
}
void block2(){
    std::unique_lock<std::mutex> lck(mut1);
    while(tcount<mmax){
        cv1.wait(lck,[](){return t2_flag;});
        if(tcount>mmax)
            break;
        print("-----------TB-----------");
        for(int i=tcount;i<=tcount+4;i++){
        print("B: "+ str(i));
        }
        tcount += 5;
        t1_flag=true;      
        cv2.notify_one();      
        t2_flag=false;          
    }
}
int main()
{
    thread t1(block1);
    thread t2(block2);
    t1.join();
    t2.join();
    return 0;
}