# Outline

## Install gdb
* If gdb is not installed, install thru package manager
  ```
  sudo apt install gdb
  ```

## Debugging with gdb
* Start simple debug session
  ```
  gcc demo.c -c -g
  gcc demo.o -o d.out -g
  gdb ./d.out
  ```
* Passing command line args

## Internal commands in gdb shell
* r - run
* c - continue
* q - quit
* s - step (step in)
* n - next (step over)
* finish   (step out)
* b - break point
* list
* info
* display
* bt - back trace 
* up
* down
