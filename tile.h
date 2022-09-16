#ifndef TILE_H 
#define TILE_H 
#include <iostream>
#include <string>

class Tile {
    public: 
      Tile (char s, int v) : suit (s), value (v) {}
      bool operator==(const Tile &t); 
      bool operator<(const Tile &t); 
      bool operator>(const Tile &t);
      void printTile() { std::cout << "[" << suit << value << "]"; }
      std::string tileToString();
      
    private: 
      char suit;
      int value;
};

#endif