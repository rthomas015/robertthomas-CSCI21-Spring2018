labtest: lab_4_unit_test.o lab_4.o
	g++ -Wall -g -o labtest lab_4.o lab_4_unit_test.o

unittest: lab_4_unit_test.cpp
	g++ -Wall -g -c lab_4_unit_test.cpp

lab_4: lab_4.cpp lab_4.h
	g++ -Wall -g -c lab_4.cpp

clean:
	rm *.o *test