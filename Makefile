CXX = g++
CXX_FLAG = --std=c++11 -g

tests: test.o game.o
	${CXX} ${CXX_FLAG} test.o game.o -o tests
	
clean:
	del -f *.o *.exe