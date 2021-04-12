CXX = g++
CXXFLAGS = std=c++0x -Wall -g

scanner: main.cpp scanner.cpp
	$(CXX) $(CXXFLAGS) -o scanner main.cpp scanner.cpp
	
clean:
	rm -f scanner *.o stdin.temp
