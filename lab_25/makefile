#creates the executable from both the object files
labtest: lab_25_unit_test.o bst_node.o bs_tree.o
	g++ -Wall -g -o test lab_25_unit_test.o bst_node.o bs_tree.o

# creates the unit test object file
bs_tree: bs_tree.cpp 
	g++ -Wall -g -c bs_tree.cpp

# creates the unit test object file
bst_node: bst_node.cpp 
	g++ -Wall -g -c bst_node.cpp

# creates the unit test object file
unittest: lab_25_unit_test.cpp 
	g++ -Wall -g -c lab_25_unit_test.cpp	

#cleans up old .o files	
clean:
	rm *.o *test