#ifndef PLAYER_H 
#define PLAYER_H 
#include <iostream>
#include <string>
#include <vector>
#include "tile.h"

class Player {
    public: 
      Player (std::vector<Tile> h) : hand(h) {}
      
    private: 
      std::vector<Tile> hand;
      std::vector<Tile> discards;
      std::vector<Tile> exposed;
};

#endif