int a=10;                   //.data, D
int b;                      //.bss,  B
static double p=5.6;        //.data, d
static double q;            //.bss,  b
const int cval=100;         //.rodata, r
static const int sval=100;  //.rodata, r

void f1() {                 //.text,  T
  //some code
}               
static void f2(int m) {     //.text,  t
}

int sum(int,int);

int main() {                //.text,  T
  int x, y, z;
  z = x+ y;  
  z = sum(x,y);             //undefined symbols, U
  //print z
  return 0;
}

/** TODO/Discussion
  g++ 3_layout.cxx -c
  nm 3_layout.o                #observe symbol states, symbol table
  objdump -t 3_layout.o

* static keyword prefix to global variables, functions
* internal vs external linkage
* Do global variables can be initialized with runtime expressions (values not known at compile time)
*/
