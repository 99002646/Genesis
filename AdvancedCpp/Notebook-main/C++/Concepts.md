## Modern C++(Advance)
* C++ 11/14 Language features
* Move Semantics
* [Trival Classes](https://www.geeksforgeeks.org/trivial-classes-c/)
* Lambdas & Callable elements
* STL Improvements
* Smart Pointers
* Concurrency and IPC
* Basic Design aspects


## [Core C++ Concepts](Core_C++)

1. Introduction
    1. Modern C++ Standards
    2. Compilers & IDEs, Toolchains
    3. Phases of development - preprocess, compile, link, tool usage, compiler options(GNU and Clang Tools)
    4. Sections of an object code - .text, .data, .bss, stack, heap, .rodata(nm/objdumb)

2. Langauge Basics
    const keyword usage on pointers & references
    const_cast, reinterpret_cast
    Memory leaks, heap analysis(Valgrind)
    Placement new operator

3. Functions
    Safe & unsafe return mechanisms
    Functions returning refereces , l-value context
    Name mangling with overloaded functions, symbol table analysis(nm/objdumb)
    extern "C" block, symbol table analysis(nm/objdumb)

4. Classs & Objects
    Object Oriented Principles
    Object relationships - is-a, has-a/part-of, using, class diagrams, arrow types(UMl Diagram)
    Multi file approach – best practices (header vs source, prototype vs definition)
    Clean initialization of object – initializer list with constructor (no assignment inside body)
    When do compiler provides default constructor implicitly
    When to implement copy constructor by programmer (when compiler provided one fails)
    Real purpose of destructor, when to implement our own?
    this keyword as hidden param in non static functions
    this keyword inside const member functions, mutable keyword usage
    Limitations of pointer to const/ref to const – which functions can be invoked?
    Non Trivial Example like MyString class
    Efficient way of passing objects
    Do this keyword applicable in static, friend functions
    Returning anonymous objects, Return Value Optimization, Copy Elision 
    Use cases of static variables, static functions
    Member Const
    Member Type

5. Operator Overloading
    Internal mechanism for Binary, Unary operators, post incr/decr
    Returning anonymous objects / named objects?
    Return by value vs Return by reference – efficiency , safe/unsafe conditions
    When to implement overloaded assignment operator (when compiler provided one fails)
    Rule of three/zero
    Overloading <<, >>  .. Reading/Writing objects
    explicit constructors
    Userdefind type conversions, e.g. int to object , vice versa
    Overloading special operators - [] , ->, ()
    Overloading new, delete operators

6. Polymorphic features & RTTI 
    Clean way of writing Derived class constructors
    Ambiguity with multiple inheritance
    Function call lookup in case of overriding
    Virtual Tables – Internal Mechanism, Dumping Virtual Tables
    Virtual Destructors
    RTTI – typeid, dynamic_cast, static_cast
    Interface design in C++ (Abstract classes)
    Inheritance vs Composition – when to use which one

7. Templates
    Implicit vs Explicit type deduction
    Implicit vs Explicit instantiation of template code (function/class)
    Overloading with templates (pass by val, by addr, by ref)
    Non Type Template parameters, Code Bloats
    Template Specialization

8. File Handling, Streams
    Stream Class Hierarchy
    Reading & Writing data (primitive types, objects)
    Formatted I/O – ios flags, manipulators
    String Streams
    Stream Iterators

9. Scoping
    Namespace – defining, symbol access, conflicts, multi level namespace
    Default Namespace, Anonymous Namespace
    Internal linkage vs External linkage

10. Data Structures & STL
    Conceptual understanding of Data Structures – arrays, linked lists, balanced trees etc
    STL Containers – Sequential (vector, list, deque), Associative(map, set, multiset, multimap)
    Internals of containers (backend data structure , complexity etc)
    Iterators ( normal, reverse, const, const reverse), stream iterators, back inserter
    Effective usage of std algorithms
    Function objects, std function objects
    Thorough understanding of std::string class members
    Implement own container, iterators, function objects
    Hash Table

11. C++ Development Tools
    0. IDE or Compiler with Editor
    1. Unit Testing Framework
    2. Code Style Plugin(Clang or Google)
    3. [Code Visualizer](http://www.pythontutor.com/cpp.html#mode=edit)
    4. Code Explorer(SourceTrail)
    5. Code Quality(Analysis -Staic(Codacy,cppcheck) and Dynamic(valgrind))
    6. CI/CD (Genics,github)
    7. Documentaion(doxygen)
    8. Design Suite(UMl Diagram-draw.io)