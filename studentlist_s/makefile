#creates the executable from both the object files
labtest: main.o student.o node.o list.o
	g++ -Wall -g -o test main.o student.o node.o list.o

# creates the student object file
main: main.cpp 
	g++ -Wall -g -c main.cpp	

#creates the list object file
list: list.cpp 
	g++ -Wall -g -c list.cpp

#creates the node object file
lab: node.cpp 
	g++ -Wall -g -c node.cpp
	
# creates the student object file
student: student.cpp 
	g++ -Wall -g -c student.cpp	

#cleans up old .o files	
clean:
	rm *.o *test