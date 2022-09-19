#ifndef TILE_H 
#define TILE_H 
#include <iostream>
#include <string>

class Tile {
    public: 
      Tile (char s, int v) : suit (s), value (v) {}
      char getSuit() {return suit;}
      char getValue() {return value;}
      bool operator==(const Tile &t); 
      bool operator<(const Tile &t); 
      std::string tileContent();
      void printTile();  
      
      
    private: 
      char suit;
      int value;
      std::string tileToString();
};

#endif