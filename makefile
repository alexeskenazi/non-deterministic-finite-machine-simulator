CXX = g++
CXXFLAGS = -Wall -g -std=c++11

all: eskenazi_p1

eskenazi_p1: eskenazi_p1.o automata.o automata-tests.o
	$(CXX) $(CXXFLAGS) eskenazi_p1.o automata.o automata-tests.o -o eskenazi_p1 

eskenazi_p1.o:	eskenazi_p1.cpp automata.h
	$(CXX) $(CXXFLAGS) -c eskenazi_p1.cpp

automata.o:	automata.cpp automata.h
	$(CXX) $(CXXFLAGS) -c automata.cpp

automata-tests.o: automata-tests.cpp automata-tests.h automata.h
	$(CXX) $(CXXFLAGS) -c automata-tests.cpp

clean:
	rm -f *.o eskenazi_p1

run: clean eskenazi_p1
	./eskenazi_p1

tests: clean eskenazi_p1
	./eskenazi_p1 test
	./eskenazi_p1 data/sample_2.txt 010111

