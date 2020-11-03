int a=10;                 //  .data   - D
int b;                    //  .bss    - B
static double p=5.6;      //  .data, internal - d
static double q;          //  .bss, internal, - b
const int cval=100;       //  .rodata
static const int sval=100;//  .rodata

void f1() { }             // .text - T
static void f2() { }      // .text,internal - t

int main() {              // .text  - T
  int x, y, z;
  z = x+ y;
  //print z
  return 0;
}
/**
  g++ 3_layout.cxx -c
  nm 3_layout.o                #observe symbol states
  objdump -t 3_layout.o
*/
