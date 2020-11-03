all: all.out 
all.out : point.o stlpoint.o stlpoint_test.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
point.o: point.cpp point.h
	g++ $< -c
stlpoint.o: stlpoint.cpp stlpoint.h
	g++ $< -c
stlpoint_test.o:stlpoint_test.cpp 
	g++ $< -c
clean:
	rm -rf *.o *.out
