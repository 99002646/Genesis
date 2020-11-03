# Hands-on & Discussion
* Makefile structure
* Syntax of a rule
  ```
  target : dependencies
  <-tab-> command to generate target
  ```

* Simple Makefile
  ```
  all:all.out

  all.out:test.o sum.o sqr.o
      gcc test.o sum.o sqr.o -o all.out
  test.o:test.c fun.h
	  gcc test.c -c
  sum.o:sum.c fun.h
	  gcc sum.c -c
  sqr.o:sqr.c fun.h
	  gcc sqr.c -c
  clean:
	  rm -rf *.o all.out
  ```
* Naming conventions for makefile (one per dir)
* targets for `make` command
* Need for the target `clean`
* What'll happen when we re run `make`
  * test.c/sum.c/sqr.o is modified
  * fun.h is modified
  * no file is modified
* Writing one more rule for `run`
