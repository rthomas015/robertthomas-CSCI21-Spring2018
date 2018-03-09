project2a: boardgame.o player.o computer.o human.o Proj1Aux.o main.o
	g++ -Wall -g -o project2a.exe boardgame.o player.o computer.o human.o Proj1Aux.o main.o

main: main.cpp
	g++ -Wall -g -c main.cpp
	
Proj1Aux: Proj1Aux.cpp
	g++ -Wall -g -c Proj1Aux.cpp
	
human: human.cpp
	g++ -Wall -g -c human.cpp
	
computer: computer.cpp
	g++ -Wall -g -c computer.cpp

player: player.cpp
	g++ -Wall -g -c player.cpp

boardgame: boardgame.cpp
	g++ -Wall -g -c boardgame.cpp

clean:
	rm *.o *test