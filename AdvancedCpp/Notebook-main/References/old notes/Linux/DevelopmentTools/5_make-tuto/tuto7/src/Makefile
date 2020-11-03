all : libsimple.a

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include

libsimple.a : sum.o sqr.o

libsimple.a:sum.o sqr.o
	ar rc $@ $^
clean:
	rm -rf *.o *.a
