# Notes

## Programming paradigms of C++
* imperative, procedural oriented features
* object oriented features
* generic programming
* functional programming

## History & C++ Standards
* Initiated by Bjarne Stroustup, as an extension of C, C with Objects
* Prior to C++98 - ANSI etc.
* C++98 standardized by ISO, standard C++
* Modern C++ standards 
  * C++11
  * C++14
  * C++17
  * C++20 (on the way)
  * C++23 (upcoming)
* GNU dialects of standards - gnu++98, gnu++11, gnu++14 etc.

## Compilers & IDEs
* Compilers - gcc/g++, clang tools, Visual Studio
* IDEs - Eclipse, Visual Studio, VS Code, Code Blocks, Dev C++, CLion etc.
* Online Compilers/IDEs

## Simple HelloWorld program
* cout, cin are objects from ostream, istream class
* <<, >> are operators
* endl is expensive, as it will flush/reset streams apart from printing new line
* Use endl sparingly

## Access Symbols from namespace
* `std::cout` everywhere, most preferred
*  Add necessary symbols only to current scope
   ```
   using std::cout;
   using std::cin;
   using std::endl;
   ```
* `using namespace std;` , will add all symbols from std namespace, least preferred method

## Phases of development
* Preprocessing
* Compilation
* Linking
> Assembling in between

## Types of errors
* Syntax errors
* Linker errors
* Runtime errors
* Logical errors

> Examples for each type of error, how to detect?

## Memory layout of a loaded process
* Code segment (.text)
* Initialized Data Segment (.data)
* Uninitialized Data Segment (.bss)
* Stack
* Heap Association
* Read only data (.rodata)

## Learning Resources
* https://www.sololearn.com/Course/CPlusPlus/
* https://learncpp.com/
* http://pythontutor.com/cpp.html (for code visualization)

## Recommended Book Reading
* C++ Primer, 5/e by Stanley B Lippman
* C++ Programming Language, 4/e, Bjarne Stroustrup
* C++ Complete Reference by Herbert Schildt
* Clean Code by Robert Martins
* Code Complete by Steve McConnell (Microsoft Press)
* Effective C++, 3/e by Scott Meyers (55 discussions, improve coding)

