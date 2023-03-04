all:	program1

program1:	project1.o card.o problem.o
	g++ -g -Wall -std=c++11 project1.o card.o problem.o -o program1

project1.o:	project1.cpp
	g++ -c project1.cpp 

card.o: card.cpp
	g++ -c card.cpp 

problem.o: problem.cpp
	g++ -c problem.cpp 

clean:
	rm -f *.gch *.o program1