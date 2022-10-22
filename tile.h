#ifndef TILE_H 
#define TILE_H 
#include <iostream>
#include <string>

class Tile {
    public: 
      Tile (char s = '-', int v = 0) : suit (s), value (v) {}
      char getSuit() const {return suit;}
      char getValue() const {return value;}
      bool operator==(const Tile &t) const; 
      bool operator<(const Tile &t) const; 
      std::string tileContent() const;
      std::string tileToString() const;
      void printTile() const;  
      
      
    private: 
      char suit;
      int value;
};

#endif