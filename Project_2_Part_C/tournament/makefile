#creates the executable from both the object files
labtest: node.o Iterator.o queue.o stack.o tournament.o 
	g++ -Wall -g -o test node.o Iterator.o queue.o stack.o tournament.o

# creates the unit test object file
tournament: tournament.cpp 
	g++ -Wall -g -c tournament.cpp	

#creates the queue object file
stack: stack.cpp 
	g++ -Wall -g -c stack.cpp

#creates the queue object file
queue: queue.cpp 
	g++ -Wall -g -c queue.cpp

#creates the iterator object file
Iterator: Iterator.cpp 
	g++ -Wall -g -c Iterator.cpp
	
#creates the node object file
lab: node.cpp 
	g++ -Wall -g -c node.cpp

#cleans up old .o files	
clean:
	rm *.o *test