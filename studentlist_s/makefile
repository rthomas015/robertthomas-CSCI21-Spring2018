#creates the executable from both the object files
labtest: student.o 
	g++ -std=c++11 -Wall -g -o test student.o

# creates the unit test object file
unittest: student.cpp 
	g++ -Wall -g -std=c++11 -c student.cpp	

#cleans up old .o files	
clean:
	rm *.o *test