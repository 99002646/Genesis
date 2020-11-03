# Outline

## Build Options
* -E for Preprocessing [link](https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm)
* -S for Compiling   >> .s
* -c for Assembling  >> .obj or .o
* -o for linking     >> out file

## Building a simple program, phase wise

gcc hello.c -E          # stop with preprocess, actual tool is cpp        
cpp hello.c             # observe preprocessed code (transformed)
cpp hello.c -o hello.i  # output the preprocessed code
gcc hello.c -c          # compile only (no link), hello.o generated
gcc hello.o -o h.out    # link with std libs, startup code
gcc hello.c -o h.out    # upto Linking
./h.out                 # executable file




## Sections of a C/C++ Process

Refer [code](layout-demo.c) for this, dump symbol table using these steps

```
gcc layout-demo.c -c -o demo.o
nm demo.o
objdump -t demo.o
```
> observe symbol states like D,C/B,T,R, d,b,t,r
> What is the meaning of these symbol states in nm/objdump output?

## nm
```
Displays information about symbols in object files, executable files, and object-file libraries.
Item 	Description
A 	    Global absolute symbol.
a 	    Local absolute symbol.
B 	    Global bss symbol.
b 	    Local bss symbol.
D 	    Global data symbol.
d 	    Local data symbol.
f 	    Source file name symbol.
L 	    Global thread-local symbol (TLS).
l 	    Static thread-local symbol (TLS).
T 	    Global text symbol.
t 	    Local text symbol.
U 	    Undefined symbol.

man nm
```

## objdump
```
Command-line program for displaying various information about object files.
ex: disassembly

To check debug related info
gcc -g file.c -o output
objdump -g output
objdump -d output
man objdump
```

## More GNU Tools, gcc/g++ options
```
gcc hello.c   -S            # generate assebly code
gcc hello.s -S -o hello.o   # assemble the code
as hello.s -o hello.o       # assemble the code
gcc hello.o -o h.out        # link, generate executable

file hello.o                # check file type
file h.out                  # check file type
nm hello.o                  # symbol table
objdump -t hello.o          # symbol table
objdump -d hello.o          # disassemble the code
readelf -h hello.o          # header analysis, decode magic number
xxd hello.c | head          # To check the file magic number 

readelf -h h.out            # header analysis
size hello.o                # section wise footprint    
size h.out                  # section wise footprint
```


