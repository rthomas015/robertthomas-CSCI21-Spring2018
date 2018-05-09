project2c:  node.o queue.o gameboard.o player.o computer.o human.o Proj1Aux.o main.o
	g++ -Wall -g -o project2c.exe node.o queue.o gameboard.o player.o computer.o human.o Proj1Aux.o main.o

main: main.cpp
	g++ -Wall -g -c main.cpp
	
queue: queue.cpp
	g++ -Wall -g -c queue.cpp

node: node.cpp
	g++ -Wall -g -c node.cpp
	
Proj1Aux: Proj1Aux.cpp
	g++ -Wall -g -c Proj1Aux.cpp
	
human: human.cpp
	g++ -Wall -g -c human.cpp
	
computer: computer.cpp
	g++ -Wall -g -c computer.cpp

player: player.cpp
	g++ -Wall -g -c player.cpp

gameboard: gameboard.cpp
	g++ -Wall -g -c gameboard.cpp

clean:
	rm *.o *test