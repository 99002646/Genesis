TARGET=sall.out
OBJS=test.o src/sum.o src/sqr.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lsimple
LIBPATH=${PWD}/src

all:sall.out

sall.out:test.o  libsimple.a
	gcc -L${LIBPATH} $< -o $@ ${LDFLAGS}

libsimple.a:
	make -C src

test.o: test.c include/fun.h

clean:
	rm -rf *.a *.o src/*.o ${TARGET} ${LIBPATH}/libsimple.a
