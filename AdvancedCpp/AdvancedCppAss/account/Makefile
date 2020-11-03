all: all.out 
all.out : account.o banking.o account_test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread	
account_test.o: account_test.cc banking.h 
	g++ $< -c
account.o : account.cc account.h
	g++ $< -c    
banking.o : banking.cc banking.h
	g++ $< -c
clean:
	rm -rf *.o *.out
