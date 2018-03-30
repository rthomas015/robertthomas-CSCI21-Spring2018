#creates the executable from both the object files
labtest: node.o test.o  
	g++ -Wall -g -o test node.o test.o  

#creates the lab2 object file
lab: node.cpp 
	g++ -Wall -g -c node.cpp

# creates the unit test object file
unittest: test.cpp 
	g++ -Wall -g -c test.cpp	

#cleans up old .o files	
clean:
	rm *.o *test 