all:	submission

submission:	p2.o contestant.o min_heap.o
	g++ -g -Wall -std=c++11 p2.o contestant.o min_heap.o -o submission

p2.o:	p2.cpp
	g++ -c p2.cpp 

min_heap.o: min_heap.cpp
	g++ -c min_heap.cpp 

contestant.o: contestant.cpp
	g++ -c contestant.cpp 

clean:
	rm -f *.gch *.o program2