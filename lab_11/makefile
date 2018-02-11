labtest: lab_11_unit_test.o money.o
	g++ -Wall -g -o labtest money.o lab_11_unit_test.o

lab_11: money.cpp money.h
	g++ -Wall -g -c money.cpp

unittest: lab_11_unit_test.cpp
	g++ -Wall -g -c lab_11_unit_test.cpp

clean:
	rm *.o *test