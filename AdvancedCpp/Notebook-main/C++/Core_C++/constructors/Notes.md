# Notes

## Need for constructor
* Default initialization(garbage/zero) in absence of constructor
* Explicit call to a function like init/open required in absence of constructor, else members will have default value

## Constructor
* Same name as class name
* No return type
* Implicitly invoked just after object creation
* Used to initialize data members of the class (Initial object state)
* Can't be invoked explicitly (once object is created)
* Typically public (will discuss some exeptions later)

## Parameterized Constructor
* Constructors can take arguments, as per initialization plan
* Overloading is possible
* Can take default arguments

## Default constructor
* Constructors with zero arguments
* In absence of any user provided constructor, compiler provides a default constructor implicitly, 
* Compiler provided default constructor is blank/do-nothing, leaves data members for default init (garbage/zero) 
* For desired initialization of object, with predefined values default constructor should be implemented by user.


## Copy constructor
* Used for object cloning, i.e. create a new object whose initial state is same as another existing object.
* In absence of any user provided copy constructor, compiler provides a copy constructor implicitly.
* Compiler provided copy constructor, does simple shallow copy, which works well for trivial classes (all members are of simple types, no pointers).
* For non trivial classes with complex data members(e.g. pointers), copy constructor must be implemented explicitly by the user for deep/safe copy of the object state.

## Initializer list with constructors
* All members of trivial(simple) type should be initialized through entry in initializer list only
* Simple members shouldn't be assigned values inside constructor body

## Destructor
* Same name as class name with ~ prefix
* No arguments, no return type
* Implicitly invoked just before object is going out of scope
* Used for any deinitialization/cleanup for the object.
* In absence of any user provided destructor, compiler provides a blank/do-nothing destructor implicitly, which is fine for trivial classes (all members are simple)
* * For non trivial classes with complex data members(e.g. pointers), destructor must be implemented explicitly by the user for any cleanup/de initialization.

> Myths & facts:- Constructor is not for allocating memory for object and destructor is not meant for releasing object's own memory. Object creation & destruction is as per scope rules & life time (local, global, dynamic objects)

## Best Practices / Guidelines
* Initialize all simple/trivial members through initializer list only
* Initialize data members through constructor only, not using set functions
* set functions are only meant for subsequent changes (after initialization)
* Don't skip initialization of any data member inside the constructor, if value is not provided through parameters, initialize with some predefined applicable value (no default value)


