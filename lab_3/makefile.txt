all: lab3

lab2test: lab_3.o
	g++ -Wall -g -o lab3 lab_3.o

lab3: lab_3.cpp
	g++ -Wall -g -c lab_3.cpp