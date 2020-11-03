all: all.out 
all.out : billing.o billing-test.o customer.o prepaid.o postpaid.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
billing-test.o: billing-test.cxx customer.h prepaid.h postpaid.h billing.h 
	g++ $< -c
billing.o : billing.cc billing.h prepaid.h postpaid.h
	g++ $< -c
prepaid.o : prepaid.cc prepaid.h customer.h
	g++ $< -c    
postpaid.o : postpaid.cc postpaid.h customer.h
	g++ $< -c
clean:
	rm -rf *.o *.out
