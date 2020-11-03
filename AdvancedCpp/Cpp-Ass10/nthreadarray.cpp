/*Example of data parallelism: using parallel sum of array using thread*/ 
#include<bits/stdc++.h>

using namespace std;
int sum=0;

void fsample(int arr[]){
	int sum1=0;
    for(int i=0;i<10;i++)
	{
		sum1=sum1+arr[i];
	}
	sum=sum+sum1;
    cout<<sum<<endl;
}

void gcompute(int arr[]){
	int sum2=0;
	for(int i=5;i<10;i++)
	{
		sum2=sum2+arr[i];
	}
	sum=sum+sum2;
    cout<<sum<<endl;
}


int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10}, n=10;
    thread tarr[n];

    for(int i=0;i<n;i++)
    {  
       if(i%2==0)
            tarr[i] = thread(fsample,arr);
       else
         tarr[i]= thread(gcompute,arr);
    }
    
    for(int i=0;i<n;i++)       
        tarr[i].join();

	cout<<"Sum of Array="<<sum<<endl;
    return 0;
}

