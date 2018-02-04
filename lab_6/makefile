labtest: lab_6_unit_test.o lab_6.o
	g++ -Wall -g -o labtest lab_6.o lab_6_unit_test.o

lab_4: lab_6.cpp lab_6.h
	g++ -Wall -g -c lab_6.cpp

unittest: lab_6_unit_test.cpp
	g++ -Wall -g -c lab_6_unit_test.cpp

clean:
	rm *.o *test