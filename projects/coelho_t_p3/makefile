all:	submission

submission:	p3.o item.o problem.o
	g++ -g -Wall -std=c++11 p3.o item.o problem.o -o submission

p3.o:	p3.cpp
	g++ -c p3.cpp 

problem.o:	problem.cpp	
	g++ -c problem.cpp

item.o:	item.cpp	
	g++ -c item.cpp

clean:
	rm -f *.gch *.o program3