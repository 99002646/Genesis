# Assignment
1. Parallel sum of large array using threads
2. Parallel sum of large array using Async tasks
3. Parallel sum of elements in STL container using threads/Async tasks
4. Implement Stack using Mutual Exclusion and Synchronization (mutex, condition variables)
5. Write a program to implement two threads, where output from both threads will 
   come,with switching after every 5 iterations.
6. Implement double linked list using shared pointers
7. Concurrent write operations to a common file, prevent race conditions using mutual exclusion techniques
8. A function to sum any no.of arguments using variadic arguments
9. Move operations on Point class
10. Implementation of own smart pointer, like std::unique_ptr and make_smart like std::make_unique

# Demos/Hands-on:-
* Thread callbacks a) normal functions b) using lambdas 
* Passing arguments to thread callbacks
  a) multiple arguments to std::thread constructor b) using std::bind b) lambdas
* Function objects as thread callbacks
* Array of thread instances
* Using delay in threads, providing time duration using chrono library
* Race condition demo , concurrent increment/decrement on global variable
* Mutex usage to avoid race conditions
* Atomic variables to avoid race conditions
* a) Secnario to generate deadlocks b) avoid deadlocks using std::unique_lock and std::lock
* Difference between unique_lock and lock_guard
* Async task demo -- simple function
* Recursive function using Async tasks
* Promise and Future demo to exchange some data
* Void future and promise (barrier)

# Additional:-
* Detachable threads
* Async launch policies
* Implementation of own shared pointer
