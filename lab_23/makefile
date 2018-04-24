#creates the executable from both the object files
labtest: lab_23_unit_test.o bst_node.o
	g++ -Wall -g -o test lab_23_unit_test.o bst_node.o

# creates the unit test object file
bst_node: bst_node.cpp 
	g++ -Wall -g -c bst_node.cpp

# creates the unit test object file
unittest: lab_23_unit_test.cpp 
	g++ -Wall -g -c lab_23_unit_test.cpp	

#cleans up old .o files	
clean:
	rm *.o *test