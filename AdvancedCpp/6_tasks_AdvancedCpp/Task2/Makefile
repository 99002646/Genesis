BUILD = build
TEST_SRC = source
TEST_OUTPUT = $(BUILD)/all.out
all: all.out 
all.out : account.o banking.o  bankingtest.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
bankingtest.o: bankingtest.cpp  banking.h
	g++ $< -c

banking.o : banking.cpp banking.h account.h
	g++ $< -c
account.o : account.cpp account.h 
	g++ $< -c    

test:$(BUILD)
	gcc $(TEST_SRC) -o $(TEST_OUTPUT) -lcunit
	./$(TEST_OUTPUT)
clean:
	rm -rf *.o *.out
	
	
	

