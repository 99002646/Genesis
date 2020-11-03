BUILD = build
TEST_SRC = source
TEST_OUTPUT = $(BUILD)/all.out
all: all.out 
all.out : contact.o address.o  adresstest.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
adresstest.o: adresstest.cpp  address.h
	g++ $< -c

address.o : address.cpp address.h contact.h
	g++ $< -c
contact.o : contact.cpp contact.h 
	g++ $< -c    

test:$(BUILD)
	gcc $(TEST_SRC) -o $(TEST_OUTPUT) -lcunit
	./$(TEST_OUTPUT)
clean:
	rm -rf *.o *.out
	
	
	

