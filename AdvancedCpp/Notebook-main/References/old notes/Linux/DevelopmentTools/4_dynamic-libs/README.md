# Outline

## Hands-on Steps
```
gcc sum.c -c
gcc sqr.c -c
gcc -shared -o libsample.so sum.o sqr.o

gcc test.c -c
gcc -L. test.o -o d1.out -lsample
LD_LIBRARY_PATH=. ./d1.out
```

## Discussion
* Concept of dynamic libs & linking
* Advantages & Disadvantages with dynamic linking
* Need for -L, -l options
* Alternate ways of running d1.out, e.g. export
* How d1.out is different from s1.out, s2.out
* Should we distribute libsample.so along with executable

# Activity
* How to link if `libsample.so` is in a diff dir, say `~/dlibs`
  ```
  gcc -shared -o ~/dlibs/libsample.so sum.o sqr.o
  #TODO: link with libsample.so in ~/dlibs
  #TODO: execute d1.out
  ```

## Analysis
```
file libsample.so
nm libsimple.so
objdump -so libsimple.a   # -t

file d1.out
ls -lh d1.out
size d1.out
ldd d1.out
```

* Usage of `ldconfig`, `/etc/ld.so.conf` 

# Using ldconfig to modify libsimple.so

* What if we want to install our library so everybody on the system can use it? 
* For that, you will need admin privileges. 
* Put the library in a standard location, /usr/lib or /usr/local/lib, 
* Modify the ld.so config file and cache.
```
  sudo cp libsample.so /usr/lib
  sudo chmod 0755 /usr/lib/libsample.so
  sudo ldconfig
  unset LD_LIBRARY_PATH
  gcc -o test.o d1.out -lsample
```

## Versioning of shared object files
```
  gcc -shared -Wl,-soname,libsample.so -o /usr/lib/libample.so.1.0.1 sum.o sqr.o
  ln -s /usr/lib/libample.so.1.0.1 /usr/lib/libsample
  ln -s -f newfile symlink   #To update the File that symlink points to
  ldconfig -n path
```