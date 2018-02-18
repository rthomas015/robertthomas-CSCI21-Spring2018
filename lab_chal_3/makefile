labtest: challenge-3-unittest.o challenge-3.o
	g++ -Wall -g -o labtest challenge-3.o challenge-3-unittest.o -std=c++11 

LC3: challenge-3.cpp LC3.h
	g++ -Wall -g -c challenge-3.cpp -std=c++11 

unittest: challenge-3-unittest.cpp
	g++ -Wall -g -c challenge-3-unittest.cpp -std=c++11 

clean:
	rm *.o *test