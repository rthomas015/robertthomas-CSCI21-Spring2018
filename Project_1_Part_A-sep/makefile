project1_partA.exe: main.o cc_check.o
	g++ main.o cc_check.o -o project1_partA.exe

main.o: main.cpp cc_check.cpp cc_check.h
	g++ -Wall -g -c main.cpp

cc_check.o: cc_check.cpp cc_check.h
	g++ -Wall -g -c cc_check.cpp

clean:
	rm *.o *test