# Build Steps

## How to compile and link

```cpp
g++ test.cxx -c     # test.o, compile only
g++ sum.cxx -c      # sum.o
g++ sqr.cxx -c      # sqr.o
g++ test.o sum.o sqr.o -o all.out   # linking
```
