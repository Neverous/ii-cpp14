CXX=/usr/bin/g++
CXXFLAGS=-Wall -Wshadow -Wextra -Woverflow -O2

all: hello hello_v2

hello: hello.cpp
	$(CXX) $(CXXFLAGS) hello.cpp -o hello

hello_v2: hello_v2.cpp
	$(CXX) $(CXXFLAGS) hello_v2.cpp -o hello_v2

clean:
	rm -f hello hello_v2
