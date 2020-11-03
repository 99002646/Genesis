# Build steps

## Compile and link

```cpp
g++ customer.cxx -c
g++ main.cpp     -c
g++ customer.o main.o -o all.out
```

* Right approach
  * class skeleton in header file 
  * definitions in source file
  * include header file only
  * compile individual source file and link object files
* Why to put definitions in source file, not in header file?
* Why including source files is not a good idea?

