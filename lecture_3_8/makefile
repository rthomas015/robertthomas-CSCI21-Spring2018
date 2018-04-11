#creates the executable from both the object files
labtest: node.o stack.o main.o 
	g++ -Wall -g -o test node.o stack.o main.o

#creates the lab2 object file
lab2: stack.cpp 
	g++ -Wall -g -c stack.cpp

#creates the lab2 object file
lab: node.cpp 
	g++ -Wall -g -c node.cpp

# creates the unit test object file
unittest: main.cpp 
	g++ -Wall -g -c main.cpp	

#cleans up old .o files	
clean:
	rm *.o *test 