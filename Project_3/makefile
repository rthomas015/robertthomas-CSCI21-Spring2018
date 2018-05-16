#creates the executable from both the object files
project3: main.o word.o bst_node.o bs_tree.o
	g++ -Wall -g -o project3 main.o word.o bst_node.o bs_tree.o

# creates word
word: word.cpp 
	g++ -Wall -g -c word.cpp	

# creates the unit test object file
bs_tree: bs_tree.cpp 
	g++ -Wall -g -c bs_tree.cpp

# creates the unit test object file
bst_node: bst_node.cpp 
	g++ -Wall -g -c bst_node.cpp

# creates main
main: main.cpp 
	g++ -Wall -g -c main.cpp	

#cleans up old .o files	
clean:
	rm *.o *test