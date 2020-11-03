all:all.out

all.out:test.o sum.o sqr.o
	gcc $^ -o $@
test.o:test.c fun.h
	gcc $< -c
sum.o:sum.c fun.h
	gcc $< -c
sqr.o:sqr.c fun.h
	gcc $< -c
clean:
	rm -rf *.o all.out
