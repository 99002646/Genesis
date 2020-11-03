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
