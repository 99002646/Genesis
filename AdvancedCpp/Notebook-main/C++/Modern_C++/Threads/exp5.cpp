//__Multiple Threads__
//g++ exp5.cpp -lpthread && ./a.out

#include <iostream>
#include <thread>
#include <chrono>
#include <string>  

// Global Variables
constexpr int max =5;
std::chrono::milliseconds delay(1000);

//___Alias Names__
#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)
#define threadSleep std::this_thread::sleep_for(delay)


void print_range(int start,int end,int tNo) {
  std::string label ="Thread " + str(tNo) + "--";
  std::string line = "Printing Range: " + str(start) + "to" + str(end);
  print(label + line);
  for(int i=start;i<=end;i++) {
    print(label+ str(i));
    threadSleep;
  }
}
int main() {
  print("Main -- Welcome");
  int start,end;
  int n=5;
  std::thread tarr[n]; // Array for threads

  for(int i=0;i<n;i++) {  // Creating Threads
    start = i*n+1;
    end = start+n;
    tarr[i] = std::thread(print_range,start,end,i);
  }

  for(int i=0;i<n;i++)      // Threads 
    tarr[i].join();
  return 0;
}

/* Output(5a)-without threadSleep

Main -- Welcome
Thread 0--Printing Range: 1to6
Thread 0--1
Thread 0--2
Thread 0--3
Thread 0--4
Thread 0--5
Thread 0--6
Thread 1--Printing Range: 6to11
Thread 1--6
Thread 1--7
Thread 1--8
Thread 1--9
Thread 1--10
Thread 1--11
Thread 4--Printing Range: 21to26
Thread 4--21
Thread 4--22
Thread 4--23
Thread 4--24
Thread 4--25
Thread 4--26
Thread 3--Printing Range: 16to21
Thread 3--16
Thread 3--17
Thread 3--18
Thread 3--19
Thread 3--20
Thread 3--21
Thread 2--Printing Range: 11to16
Thread 2--11
Thread 2--12
Thread 2--13
Thread 2--14
Thread 2--15
Thread 2--16

* Output(5b)-with threadSleep 

Main -- Welcome
Thread 1--Printing Range: 6to11Thread 0--Printing Range: 1to6

Thread 0--1
Thread 1--6
Thread 4--Printing Range: 21to26
Thread 3--Printing Range: 16to21Thread 4--21

Thread 2--Printing Range: 11to16Thread 3--16

Thread 2--11
Thread 0--2
Thread 4--22
Thread 1--7
Thread 2--12
Thread 3--17
Thread 2--13Thread 0--3
Thread 3--18

Thread 1--8
Thread 4--23
Thread 0--4
Thread 3--19
Thread 1--9
Thread 2--14
Thread 4--24
Thread 1--10Thread 0--5

Thread 2--15
Thread 4--25
Thread 3--20
Thread 1--11
Thread 2--16
Thread 3--21
Thread 4--26
Thread 0--6

*/