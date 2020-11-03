#include <iostream>
 
#define PRINT_JOE
 
int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // if PRINT_JOE is defined, compile this code
#endif
 
#ifdef PRINT_BOB
    std::cout << "Bob\n"; // if PRINT_BOB is defined, compile this code
#endif
 
    return 0;
}