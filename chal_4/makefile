labtest: challenge-4-unittest.o challenge-4-spec.o
	g++ -Wall -g -o labtest challenge-4-spec.o challenge-4-unittest.o

challenge4: challenge-4-spec.cpp
	g++ -Wall -g -c challenge-4-spec.cpp

unittest: challenge-4-unittest.cpp
	g++ -Wall -g -c challenge-4-unittest.cpp 

clean:
	rm *.o *test