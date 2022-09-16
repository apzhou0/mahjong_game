#include <iostream>
#include "game.h"

Game::Game() {
    gameOver = false;
    char bamboo = 'b';
    char dot = 'd';
    char thousand = 't';
    char special = 's';
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 10; j++) {
          Tile t (bamboo, j);
          deck.push_back(t);
          count++;
          t = Tile(dot, j);
          deck.push_back(t);
          count++;
          t = Tile(thousand, j);
          deck.push_back(t);
          count++;
        }
        for (int j = 1; j < 8; j++) {
          Tile t (special, j);
          deck.push_back(t);
          count++;
        }
    }
}

void Game::printDeck() {
    for (int i = 0; i < deck.size(); i++) {
            deck.at(i).printTile();
    }
}