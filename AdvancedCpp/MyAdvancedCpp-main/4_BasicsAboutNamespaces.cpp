#include <iostream> // imports the declaration of std::cout
 
using namespace std; // makes std::cout accessible as "cout"
 
int cout() // declares our own "cout" function
{
    return 5;
}
 
int main()
{
    //this is commented out because it is showing error
    //cout << "Hello, world!"; // Compile error!  Which cout do we want here?  The one in the std namespace or the one we defined above?
 
    return 0;
}