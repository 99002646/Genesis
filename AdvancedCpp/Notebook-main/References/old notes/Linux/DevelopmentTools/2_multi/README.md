# Outline

## How to compile and link

gcc test.c -c                        # generates test.o
gcc sum.c -c                         # generates sum.o
gcc sqr.c -c                         # generates sqr.o
gcc test.c sum.c sqr.c -c
gcc test.o sum.o sqr.o -o all.out    # linking, combines all object files & std libs, generates executable
./all.out

> Identify errors when one of the object file is missing during linking

## Analysis

nm sum.o sqr.o
objdump -t sum.o sqr.o
nm test.o
objdump -t test.o

# Activity
* If the file are in different folder
    - Change the work directory where it contains all the .c files
    - from the work directory call the files with address
    - eg. - sum/sum.c, sqr/sqr.c, inc/fun.h

* How to Compile and link?
    - gcc filename.c -o a.out

* How to define a Macro Run time?
    You can't. Macros are expanded by the Preprocessor, which happens even before the code is compiled. ... If you need to change something at runtime, just replace your macro with a real function call.

* Can we create a Bash Script file and add all commands and run the script to compile and execute the program?
    Yes - Make file and Shell scripting is possible