#creates the executable from both the object files
labtest: node.o doubly.o test.o 
	g++ -Wall -g -o test node.o doubly.o test.o

#creates the doubly linked list object file
list: doubly.cpp 
	g++ -Wall -g -c doubly.cpp

#creates the node object file
lab: node.cpp 
	g++ -Wall -g -c node.cpp

# creates the unit test object file
unittest: test.cpp 
	g++ -Wall -g -c test.cpp	

#cleans up old .o files	
clean:
	rm *.o *test