EXECUTABLE = main
OBJECT_FILES = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADER_FILES = $(wildcard *.h)
CPPFLAGS = -g --std=c++11 -Wno-c++11-extensions -O3

$(EXECUTABLE): $(OBJECT_FILES)
	g++ $(OBJECT_FILES) -o $@ $(CPPFLAGS)

%.o: %.cpp $(HEADER_FILES)
	g++ -c $< -o $@ $(CPPFLAGS)

clean:
	rm -f *.o $(EXECUTABLE)