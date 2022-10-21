#ifndef PLAYER_H 
#define PLAYER_H 
#include <iostream>
#include <string>
#include <vector>
#include "tile.h"

class Player {
    public: 
      Player(std::vector<Tile> h) : hand(h) {}
      void printHand() const;
      void printDiscards() const;
      void printExposed() const;
      void sortHand();
      void drawTile(Tile t);
      void discard(std::string s);
      bool canPong(Tile t) const;
      bool pong(Tile t);
      bool chow(Tile t);
      bool hasWon() const;
      
    private: 
      std::vector<Tile> hand;
      std::vector<Tile> discards;
      std::vector<Tile> exposed;
      bool isStraight(Tile t1, Tile t2, Tile t3) const;
};

#endif