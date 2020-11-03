# Notes

## Pointers & References to objects
* Passing objects by address/by reference to other functions
* const keyword prefix to avoid any modification to object state
* A pointer / reference prefixed with const prefix (pointer to const/reference to const) can invoke const member functions only.
* But a normal pointer/reference can access all member functions (const, non-const)

## Scope & lifetime of objects
* Local objects - function beginning to function end, stored on stack
* Global object - program beginning to program end, stored in data segment (.data/.bss)
* Dynamic objects - between new to delete, stored on heap
* If compiler provided default constructor executes on object, default initial values apply. 

## Static Variables
* Common memory irrespective of no.of objects
* Class specific data, instead of object/instance specific
* Must be defined explicitly outside the class (No memory applicable for static member declared inside the class)
* Can be accessible by class name using ::

## Static Functions
* Can be invoked by class name using ::
* Meant for any class specific common operation
* Can't access non-static variables or non-static functions
* Do this keyword applicable inside static functions?

## Friend functions
* Friend functions are not member functions of the classs
* Can access private data members of the class also
* How objects are accessible to friend functions?
  * Passed as parameters 
  * Created locally
* Do this keyword applicable inside friend functions?


