/*Example of data parallelism: using parallel sum of array using thread*/ 
#include<bits/stdc++.h>

std::chrono::milliseconds delay(1000);
#define threadSleep std::this_thread::sleep_for(delay)

#define print(msg) std::cout << msg << std::endl
using namespace std;
int sum=0;
std::mutex m1;

void fsample(int arr[]){
	print("TA");
	threadSleep;
	int sum1=0;
    for(int i=0;i<5;i++)
	{
		sum1=sum1+arr[i];
	}
	print("sum lock-TA");
	m1.lock();
   
	sum=sum+sum1;
	threadSleep;
	print("sum unlock-TA");
	m1.unlock();
}

void gcompute(int arr[]){
	print("TB");
	int sum2=0;
	for(int i=5;i<10;i++)
	{
		sum2=sum2+arr[i];
	}
	print("sum lock-TB");
	m1.lock();

	print("sum unlock-TB");
	sum=sum+sum2;
	m1.unlock();
}


int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	thread t1(fsample,arr);    
    thread t2(gcompute,arr);
    t1.join();     
    t2.join();   
	cout<<"Sum of Array="<<sum<<endl;
    return 0;
}

