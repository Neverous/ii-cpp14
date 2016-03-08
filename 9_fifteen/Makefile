solve : Makefile   solve.o fifteen.o
	$(CXX) $(CXXFLAGS) -o solve   solve.o fifteen.o

solve.o : Makefile   solve.cpp   fifteen.h move.h
	$(CXX) $(CXXFLAGS) -c solve.cpp -o  solve.o

fifteen.o : Makefile   fifteen.cpp   fifteen.h move.h
	$(CXX) $(CXXFLAGS) -c fifteen.cpp -o  fifteen.o

clean:
	-rm -f *.o solve
