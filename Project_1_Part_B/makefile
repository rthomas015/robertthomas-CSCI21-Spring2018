labtest: main.o transactions.o creditcard.o goldcard.o platcard.o corpcard.o
	g++ -Wall -g -o labtest main.o transactions.o creditcard.o goldcard.o platcard.o corpcard.o

main: main.cpp
	g++ -Wall -g -c main.cpp
	
corpcard: corpcard.cpp
	g++ -Wall -g -c corpcard.cpp
	
platcard: platcard.cpp
	g++ -Wall -g -c platcard.cpp
	
goldcard: goldcard.cpp
	g++ -Wall -g -c goldcard.cpp
	
creditcards: creditcard.cpp
	g++ -Wall -g -c creditcard.cpp

transactions: transactions.cpp transactions.h
	g++ -Wall -g -c transactions.cpp

clean:
	rm *.o *test