CXX = g++
CXXFLAGS = -Wall -g -std=c++11

all: eskenazi_p1

eskenazi_p1: eskenazi_p1.o automata.o
	$(CXX) $(CXXFLAGS) eskenazi_p1.o automata.o -o eskenazi_p1 

eskenazi_p1.o:	eskenazi_p1.cpp automata.h
	$(CXX) $(CXXFLAGS) -c eskenazi_p1.cpp

automata.o:	automata.cpp automata.h
	$(CXX) $(CXXFLAGS) -c automata.cpp

clean:
	rm -f *.o eskenazi_p1

run: clean eskenazi_p1
	./eskenazi_p1
	
