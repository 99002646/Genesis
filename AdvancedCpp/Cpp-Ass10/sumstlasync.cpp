/*Example of data parallelism: using  STL parallel sum of array using async*/ 

#include<bits/stdc++.h>

using namespace std;

int sumArr(int *arr,int start,int stop){
	return std::accumulate(arr+start, arr+stop, 0); // for array summation
}

int main(){

	int size = 1000,total=0;
	int * arr = new int[size];
	std::fill_n(arr, size, 1); // to fill all the array index with 1.
	
    /*int totalsum = sumArr(arr,0,size); //for single thread
	cout << "SingleT-- = " <<totalsum<<endl;*/

    /*To divide the array into 4 parts and then finding the sum*/

	std::future<int> s1 = std::async(&sumArr,arr,0,size/4);
	std::future<int> s2 = std::async(&sumArr,arr,size/4,2*size/4);
	std::future<int> s3 = std::async(&sumArr,arr,2*size/4,3*size/4);
	std::future<int> s4 = std::async(&sumArr,arr,3*size/4,size);
	
    /*usuing get to retrive the value from partioned sum.
     which can be use after the prime operation only*/
    
    total = s1.get()+s2.get()+s3.get()+s4.get(); 

	cout << "Summation of the array element= " <<total<<endl;

    return 0;
}