#creates the executable from both the object files
labtest: node.o queue.o test.o 
	g++ -Wall -g -o test node.o queue.o test.o

#creates the queue object file
queue: queue.cpp 
	g++ -Wall -g -c queue.cpp

#creates the node object file
lab: node.cpp 
	g++ -Wall -g -c node.cpp

# creates the unit test object file
unittest: test.cpp 
	g++ -Wall -g -c test.cpp	

#cleans up old .o files	
clean:
	rm *.o *test