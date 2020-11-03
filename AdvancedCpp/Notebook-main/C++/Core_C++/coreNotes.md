# Notes

## Basics
[std](https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/)

### Namespace
* Namespaces were introduced into C++ to resolve identifier name conflicts.
* This ensured that two objects can have the same name and yet be treated differently if they belonged to different namespaces. 
* Namespace declarations appear only at global scope. 
    namespace <name>{
        int z;
    }
    name::z
* Members inside the unnamed namespace can only be accessed in same file.  
* Unnamed namespace limits access of class, variables, function and objects to the file which it is defined.  
* Functionality is similar to static keyword. Static variables limits the access of global variable and functions to the file in which they are defined. 
* Difference between unnamed namespace and static keyword is that static keyword can be used with variable, function and objects but not with user defined class. 

### using
    Using keyword is used to: 
    a. Bring a specific member from the namespace into the current scope. 
    b. Bring all members from the namespace into the current scope. 
    c. Bring a base class method or variable into the current class scope. 

    using std::cout     --> gets cout of std namespace to current scope
    using namespace std --> gets all the type and class declaration in the std namescope


### Alias Names
1. typedef <existingName> <NewName>
    * typedef 
    * alias names for type
    * done by compiler
[typedef](https://www.studytonight.com/c/typedef.php)

2. #define <newName> <existingName>
    * done by preprocessor directive
    * alias name for both values and types


### References
    * Alternate Name or alias name for variable 
        int x = 10; 
        int& ref = x;       // ref/x is same variable
        ref = 20;          // x = 20

    * const reference(const int&) for constant or variable as argument
       
       int& for only variable as argument

       void add(int& a){
       }
       add(20)  // error
       x = 20 
       add(x)   // variable as argument

       void(const int&a){}
        add(20) // ok

    * it is same as const pointer ie.  reference cannot be re-assigned, 

    * no null assignment

    * onelevel of indirection
    int& p =a;
    int&& q = p; // not allowed

    * used as function parameters design

    * dont use reference for containers or multi element datatype


    https://www.geeksforgeeks.org/references-in-c/

## Functions
* Parameter : Input for the Function Block
* Argument : Values passed

## Classes
Data members of a class may be declared as const . Such a data member must be initialized by the constructor using an initialization list. Once initialized, a const data member may never be modified, not even in the constructor or destructor.

## I/O
### Boolean Formatting
    noboolalpha - for 1/0
    boolalpha - for true/false

## Reference Links
    https://www.geeksforgeeks.org/templates-cpp/