# Notes

## Basics & some facts
* Class is a collection of variables & functions
* Object is a logical entity, which encapsulates related data and operations (attributes, behavior)
* Object is an instance of the class
* Class is an outline/skeleton/blueprint for the objects
* Object state - values of data members at any point of time (snapshot)
* If multiple objects are instantiated from a class, each object will have it's own memory for data members (instance data/non-static data)
* The memory segment for object (data members) depends on scope of creation - local, global, dynamic objects, i.e stack, .data/.bss or heap based on scope.
* But one copy of member functions will be there in code segment (.text)
* Member functions operate on respective data members, based on object by which member function is invoked.

## Access specifiers
* public - can be accessible outside the class also
* private - accessible within the class only
* All data members must be private, ahering to data hiding principle
* Typically all member functions are public
* Few functions may be private, known as helper functions

## this keyword
* An implicit pointer to object by which member function is invoked
* It's a hidden parameter for all non-static functions (instance functions), pointing to collection of data members of concerned object.

## const member functions
* A function which doesn't modify object state (any data member) is known as immutable operation
* Immutable functions can be suffixed with const keyword, known as const member functions
* No data member can be modified inside const member function
* const keyword suffix in prototype/definition/both?

## Best Practices / Guidelines
* All data members must be private (strictly data hiding)
* const suffix for all immutable operations
* Follow suitable naming conventions for class name, data members, member functions
* Meaningful names for classes, variables, member functions
* Avoid redundant parameters, where information is available through data members
* Avoid redundant data members (which can be computed from others)
* Avoid console i/o, especially console input inside business functions,especially inside cosntructors , instead take necessary values as parameters. [ Testable code ]
* Try to return the results, error codes instead of printing inside functions [ Testable code ]
* Avoid hard coded values which can vary across objects, instead take them as parameters
* Use logging techniques instead of regular console output


