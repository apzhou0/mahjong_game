#ifndef PLAYER_H 
#define PLAYER_H 
#include <iostream>
#include <string>
#include <vector>
#include "tile.h"

class Player {
    public: 
      Player(std::vector<Tile> h) : hand(h), tripleCount(0) {}
      void printHand();
      void printDiscards();
      void printExposed();
      void sortHand();
      void drawTile(Tile t);
      void discard(std::string s);
      /*bool pong(Tile t); tripleCount++
      bool chow(Tile t); tripleCount++ */
      bool hasWon();


      
    private: 
      std::vector<Tile> hand;
      std::vector<Tile> discards;
      std::vector<Tile> exposed;
      bool canPong(Tile t);
      bool canChow(Tile t);
      bool hasPair();
      int tripleCount;
};

#endif