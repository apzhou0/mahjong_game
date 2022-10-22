#ifndef PLAYER_H 
#define PLAYER_H 
#include <iostream>
#include <string>
#include <vector>
#include "tile.h"

class Player {
    public: 
      Player(std::vector<Tile> h, int s) : hand(h), id(s) {}
      void printHand() const;
      void printDiscards() const;
      void printExposed() const;
      void sortHand();
      void drawTile(Tile t);
      bool discard(std::string s);
      bool pong(Tile t);
      bool chow(Tile t);
      int winningHand(std::vector<Tile> tiles) const;
      bool canWin(Tile t) const;
      void printUser() const;
      void printOpp() const;
      bool playTurn(Tile fromUser, Tile fromDeck);
      std::vector<Tile> hand;
      std::vector<Tile> discards;
      std::vector<Tile> exposed;
      
    private: 
      int id; 
      std::string name() const;
      bool moreThanOne(Tile t) const;
      bool canChow(Tile t) const;
      bool canPong(Tile t) const;
      bool isStraight(Tile t1, Tile t2, Tile t3) const;
};

#endif