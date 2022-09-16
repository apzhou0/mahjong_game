#ifndef GAME_H 
#define GAME_H 
#include <iostream>
#include <string>
#include "player.h"

class Game {
    public: 
      Game();
      void printDeck();
 
    private: 
      std::vector<Tile> deck;
      bool gameOver;
      
};

#endif