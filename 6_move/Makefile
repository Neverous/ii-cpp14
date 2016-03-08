all: move average polynomial

move: xx.h move.cpp
	$(CXX) $(CXXFLAGS) move.cpp -o move

average: average.cpp rational.o
	$(CXX) $(CXXFLAGS) average.cpp rational.o -o average

rational.o: ../1_matrix/rational.cpp
	$(CXX) $(CXXFLAGS) -c ../1_matrix/rational.cpp -o rational.o

polynomial: polynomial.cpp rational.o
	$(CXX) $(CXXFLAGS) polynomial.cpp rational.o -o polynomial

clean:
	-rm -f move average rational.o polynomial
