#CXX=g++
#CXXFLAGS= -Wall -Werror -std=c++11 -O3

all: freqtable

freqtable: frequency.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o freqtable

clean:
	-rm -f freqtable
