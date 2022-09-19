CXX = g++
CXX_FLAG = --std=c++11 -g

tests: test.o game.o player.o tile.o
	${CXX} ${CXX_FLAG} test.o game.o player.o tile.o -o tests
	
clean:
	del -f *.o *.exe