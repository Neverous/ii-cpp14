CXX=/usr/bin/g++
CXXFLAGS=-Wall -Wshadow -Wextra -Woverflow -O2 --std=gnu++11 -DNDEBUG

all: stack_test

stack.o: stack.h stack.cpp
	$(CXX) $(CXXFLAGS) stack.cpp -c -o stack.o

stack_test: stack.o stack_test.cpp
	$(CXX) $(CXXFLAGS) stack.o stack_test.cpp -o stack_test

test: stack_test
	valgrind --leak-check=yes ./stack_test

clean:
	rm -f stack.o stack_test
