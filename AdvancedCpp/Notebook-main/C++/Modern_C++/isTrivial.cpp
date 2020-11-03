/* __ Trivial Classes in C++

* Classes with defualt special fucntions provided by the compiler
* Header:   <type_traits>
* syntax:   std::is_trivial<ClassName>::value
* Features:
  uses the implicitly defined default, copy and move constructors, copy and move assignments, and destructor.
  has no virtual members.
  has no non-static data members with brace- or equal- initializers.
  its base class and non-static data members (if any) are themselves also trivial types.

https://en.cppreference.com/w/cpp/types/is_trivial

*/


#include <type_traits>
#include <iostream>

using namespace std;

class A {};             // Class with default constuctor
class B { B() {} };     // Class with constructor
class C : B {};
class D { virtual void fn() {} };

int main() {


    cout<<boolalpha;    // get output bool values in true or false
    cout<< "A:"<< is_trivial<A>::value <<endl; 
    cout<< "A:"<< is_trivial<A>() <<endl;
    cout<< "B:"<< is_trivial<B>::value <<endl; 
    cout<< "C:"<< is_trivial<C>::value <<endl; 
    cout<< "D:"<< is_trivial<D>::value <<endl; 
    
    return 0;
}

/* Output

A:true
B:false
C:false
D:false

  */