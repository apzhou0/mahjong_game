CXX = g++
CXX_FLAG = --std=c++11 -g

game: main.o game.o player.o tile.o
	${CXX} ${CXX_FLAG} main.o game.o player.o tile.o -o game
	
clean:
	del -f *.o *.exe