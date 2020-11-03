all: all.out 
all.out : account.o banking.o SavingsAccount.o CreditAccount.o account_test.o banking_test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
account.o: account.cpp account.h
	g++ $< -c
banking.o: banking.cpp banking.h account.h CreditAccount.h SavingsAccount.h 
	g++ $< -c
SavingsAccount.o: SavingsAccount.cpp SavingsAccount.h account.h
	g++ $< -c
CreditAccount.o: CreditAccount.cpp CreditAccount.h account.h
	g++ $< -c
account_test.o : account_test.cpp SavingsAccount.cpp CreditAccount.h SavingsAccount.h 
	g++ $< -c    
banking_test.o : banking_test.cpp account.h CreditAccount.h SavingsAccount.h banking.h
	g++ $< -c
clean:
	rm -rf *.o *.out
