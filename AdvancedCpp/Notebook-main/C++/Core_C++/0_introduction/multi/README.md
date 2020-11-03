# Build Steps

## How to compile and link

```cpp
g++ test.cxx -c     #compile only/stop with compilation no linking
g++ sum.cxx -c
g++ sqr.cxx -c
g++ test.o sum.o sqr.o -o all.out   # linking several object files
```

* What if sum.o or sqr.o is missing during linking?
* What if test.o is missing during linking?
* What should we include - header files or source files?
* What do header file containes
* Best practices
  * Include header files only, not source files
  * Don't keep definitions in header files
  * Provide defintions in source files and compile them independently
  * Keep only function prototypes, class skeleton code in header files

