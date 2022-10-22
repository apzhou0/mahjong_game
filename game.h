#ifndef GAME_H 
#define GAME_H 
#include <iostream>
#include <string>
#include "player.h"

class Game {
    public: 
      Game();
      ~Game();
      void play();
 
    private: 
      std::vector<Tile> deck;
      Player *opponent;
      Player *realUser;
      void printDeck();
      bool gameOver();
};

#endif