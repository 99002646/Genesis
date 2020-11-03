# Notes

## Reference variables
* Alias to existing variables, any expression representing valid memory location
* References must be initialized (with valid memory location)
* Once initialized, references can't change their binding (can't point to any other memory location) throughout the life time.
* Any changes (write operation) to references, reflect to original variables also and vice versa
* Any no.of references can be created for same variables, A reference can be created to another reference (any expression with l-value)
* Normal (non const) references can't be created for constants/literals or any expression without l-value (r-value only expressions)
* Unlike pointers, references doesn't required any derference syntax for read/write operations.
* Real purpose of references ??  (parameter passing)

## const keyword usage
* pointer to const
* const pointer
* reference to const
* errors when trying to modify value through pointer to const/reference to const
* binding address of const variable to a normal pointer leads to syntax error in C++.
* binding const variable to a normal reference leads to syntax error in C++.
  ```
  const int cval=100;
  int *ptr=&cval; //error
  int& ref=cval;  //error
  ```

## new & delete operators
* syntax of new operator for single variable, 1D array
* syntax of delete operator for single variable, 1D array
* memory leaks in absence of delete

## Strict prototyping
* prototype is must for all C++ functions (thus header files also)
* Calling a function without prototype will lead to syntax error
 
## Parameter passing in C++
* pass by value
* pass by address
* pass by reference

* Significance of pass by address/reference 
  * to retrieve data from called functions (out parameters, fetch results)
  * passing large objects efficiently (compared to pass by value)

## Return mechanisms in C++
* return by value
* return by address
* return by reference
* Never return adddress/reference to local variables/params(which are on stack frame)
> Safe & efficient return mechanisms?

## Function overloading
* Function signature - function name + list of parameter types
* Two or more functions with same name but different parameters (different signature)
* Variance only in return type is not considered as overloading (as not part of signature), i.e. two functions can't have same parameter list just by differing return type

## Resolution of function call 
* Identify all functions with same name as function call, consider them as candidate functions
* If no candidate function (no match by function name), call will be failure (syntax error)
* Among one more candidate functions
  * Identify suitable definition with exact match, if so call will be successful
  * If no exact match, try for near matches with some implicit conversions
      * If only one near match found, call will be successful
      * If no near match at all, call will be failure (syntax error)
      * If multiple near matches possible, call will be ambiguous (syntax error)

## Default arguments
* Some parameters can be assigned with pre-defined values
* In absence of user provided arguments, these default values will be considered
* Default value will be ignored if there is an explicit argument
* Default values must be assigned from right to left only, i.e. if an intermediate parameter has default value, all subsequent parameters should have default value
* Combination of default values + overloaded function (matching signature, with excluded parameters having defaulr values) lead to ambiguity

