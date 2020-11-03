## Concurrency and IPC

### Threads
* sub tasks in a process
* Supported by C++11 standard
* Shared Resources
* Concurrency Executions
    All the threads can run simultaneously
* Applications
    * Multiple Activity in YouTube,Browser
    * Multiple Client Handling(Main Thread listening to clients)
* Categories Achieved:
    Task Driven Parallelism(Cookie functions are different,Data may or mayn't be same)
    Data Driven Parallelism(Cookie function is same,Data is Changed)
        Eg. Parallel Sum of large Array
* Constructor Accepts
    * Normal Functions
    * Lambda Expressions
    * Binded Functions
    * Function ObjectS
* Threads are scheduled by OS default
    std::thread
    std::async

### IPC 
* Race Condition
    when Changes applied from multiple threads at the same time leads to race condition which effects in uncertain results

* Critical Section
    A section where it alters or uses the shared resources 
    * Entry Section - Allows/Blocks the Other threads
    * Exit Section

* Mutual Exclusion
    It prevents the simultaneous access to the shared resources
    * Techniques
        * Semophores(no c++ support)
            For Multiple Shared Resource Access
        * Spinlocks(no c++ suppport)
        * Mutex
            for single Shared resources between the threads
        * Atomic Variables(c++)
            Other Threads cant access this variable if this is used by one thread

* Signaling and Synchronization
    * Semaphores
    * Condition Variable