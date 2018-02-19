labtest: main.o pet.o bird.o dog.o cat.o
	g++ -Wall -g -o labtest main.o pet.o bird.o dog.o cat.o

main: main.cpp
	g++ -Wall -g -c main.cpp
	
cat_lab: cat.cpp cat.h
	g++ -Wall -g -c cat.cpp
	
dog_lab: dog.cpp dog.h
	g++ -Wall -g -c dog.cpp

bird_lab: bird.cpp bird.h
	g++ -Wall -g -c bird.cpp

pets_lab: pet.cpp pet.h
	g++ -Wall -g -c pet.cpp

clean:
	rm *.o *test