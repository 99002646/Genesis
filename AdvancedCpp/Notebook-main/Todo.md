# Todo List
* Oct 22
* Study of Core C++ (22nd)
* Study of Advanced C++(23rd)
    - Part1
    - Part2
    - Coding Tasks 
    - Project Implementation
* SDLC (22)

## Oct 22
1. Tuple
2. Regular Expression
    Bind
    lambda
    Placeholder
3. Atomic Variable
6. Prevent Loop overlap using mutex(exp 9)
7. Unique Lock,Lock_guard and unique guard(exp 10a,b)
8. exp(11)
    Deadlock Scenario 1(2 Shared Resources)
    std::mutex m1;
    std::mutex m2;

    T1                  T2   
    m1.lock()           m2.lock
    delay()             m1.lock
    m2.lock()                   

    Solution:
    std::unique_lock<std::mutex> u1(m1,std::def_lock)  //Global
    std::unique_lock<std::mutex> u2(m2,std::def_lock)
    std::lock(u1,u2)
9. Pre Read
    std::condition_variables
    std::async
    std::future
    std::promise

Activity:-
* Post read of covered topics (thread, mutex, locks etc)
* Pre-read of next topic
* Coding Tasks
* File Handling, Namespaces (if pending)
* Exception Handling, give a try

* Vine Re


## Oct 21
Activities:-
* post read of covered topics + practice examples
    - Smart Pointers
    - Universal Pointers
* continue coding tasks
* refresh thread & ipc concepts (linux os, posix apis)
	* threads
	* mutex
	* semaphore
	* producer consumer problem
	* deadlocks
Further:-
* concurrency in C++ ==> std::thread, std::async
* IPC techniques  ==> std::mutex, some locks, std::condition_variable etc.
* std::future, std::promise (if time permits


## Oct 20
1. refresh move semantics, lambdas (covered topics)
    * check for the trivial and non trivial classes
    * Check copy constructor for trivial and non trivial classes
    * Algorithms and Lambda(https://en.cppreference.com/w/cpp/algorithm)
    * Apply all this concepts  
2. explore STL algorithms, apply in coding tasks with lambdas
3. self study (try) -- file handling -- ofstream, ifstream
4. pre-read
    std::bind
    some topics on templates
    smart pointers
5. vs setup for code style,visualization and analysis


## Study List

* function pointer and all pointers
* heap block
* return value optimization

2. Linux
* Process and Threads
* Scheduling

3. SDLC
* V Model
* Agile Model
* Software Testing
* Boundary Conditions

4. Python
* Unit Testing

5. Medical Devices
* Regulations and Design Control
    https://www.iso.org/obp/ui/#iso:std:iso:13485:ed-3:v1:en

## Project List
1. C++(MoneyWallet)
2. Linux
3. Pyhton