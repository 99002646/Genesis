/* __Example4__ Data Driven Threads__
Here threads are associated with same functions and different arguments

*/

#include <iostream>
#include <thread>
#include <functional>
#include <string>

// Global Variables
constexpr int max=10;
std::chrono::milliseconds delay(1000);

//__Alias Names__
#define print(msg) std::cout << msg << std::endl
#define str(i) std::to_string(i)
#define threadSleep std::this_thread::sleep_for(delay)


void compute(std::string label)
{
    for(int i=1;i<=max;i++){
    print("Thread "+label+ "--" + str(i));
    //threadSleep;
    }
}


int main()
{ 
  print("Main--Welcome");
  std::thread t1(std::bind(compute,"A"));
  std::thread t2(compute,"B");
  t1.join();
  t2.join();
  print("thank you");
  return 0;
}
  


/* Output(4a)-threadSleep activated

Main--Welcome
Thread B--1
Thread A--1
Thread B--2Thread A--2

Thread B--3
Thread A--3
Thread B--4
Thread A--4
Thread B--5
Thread A--5
Thread B--6
Thread A--6
Thread B--7
Thread A--7
Thread B--8
Thread A--8
Thread A--9Thread B--9

Thread A--10
Thread B--10
thank you

--> Output(4b)- without threadSleep

Main--Welcome
Thread B--1
Thread B--2
Thread B--3
Thread B--4
Thread B--5
Thread B--6
Thread B--7
Thread B--8
Thread B--9
Thread B--10
Thread A--1
Thread A--2
Thread A--3
Thread A--4
Thread A--5
Thread A--6
Thread A--7
Thread A--8
Thread A--9
Thread A--10
thank you

* Observations
  * In 4a active threads toggles in the cpu when ever it enters sleep 
  * In 4b Thread 1 or 2 is scheduled based on the OS and it finish the thread completely and executes the other threads
*/
