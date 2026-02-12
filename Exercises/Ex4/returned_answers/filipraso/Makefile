CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -fPIC

all: libtrack.so libpsim.so test_classes

Track.o: Track.cpp
	$(CXX) $(CXXFLAGS) -c Track.cpp -o Track.o

PSim.o: PSim.cpp
	$(CXX) $(CXXFLAGS) -c PSim.cpp -o PSim.o

libtrack.so: Track.o
	$(CXX) -shared -o $@ Track.o

libpsim.so: PSim.o libtrack.so
	$(CXX) -shared -o $@ PSim.o ./libtrack.so

test_classes: test_classes.cpp libpsim.so libtrack.so
	$(CXX) -std=c++17 test_classes.cpp ./libpsim.so ./libtrack.so -o $@

run: all
	./test_classes

clean:
	rm -f *.o *.so test_classes

.PHONY: all run clean
