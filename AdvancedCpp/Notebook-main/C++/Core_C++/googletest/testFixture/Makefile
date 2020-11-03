all:all.out
all.out:account.o account_test_f.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
%.o:%.cc
	g++ $< -c
clean:	
	rm -rf *.o *.out
run:all.out	
	./all.out
