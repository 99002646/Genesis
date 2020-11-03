#include <iostream>
#include <string>
#include <thread>
#include <future>

#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)

int sumArray(int *arr,int start,int end){
    int sum=0;
    for(int i=start;i<=end;i++)
        sum+=arr[i];
    return sum;
}   


int main(){
print("Main");
            // 0,1,2,3,4,5,6,7,8,9
int arr[10] = {1,2,3,4,5,6,7,8,9,10};

std::future<int> result1;
std::future<int> result2;
std::future<int> result3;

result1 = std::async(sumArray, arr, 0,3);
result2 = std::async(sumArray, arr, 4,7);
result3 = std::async(sumArray, arr, 8,9);

print("Results Computing...");
int res = result1.get()+result2.get()+result3.get();
print("Result: " + str(res));

print("end");


}