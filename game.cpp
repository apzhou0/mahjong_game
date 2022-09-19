#include <iostream>
#include <algorithm> 
#include <random> 
#include <chrono>
#include "game.h"

Game::Game() {
    gameOver = false;
    char bamboo = 'b';
    char dot = 'd';
    char thousand = 't';
    char special = 'z';

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 10; j++) {
          Tile t (bamboo, j);
          deck.push_back(t);
          t = Tile(dot, j);
          deck.push_back(t);
          t = Tile(thousand, j);
          deck.push_back(t);
        }
        for (int j = 1; j < 8; j++) {
          Tile t (special, j);
          deck.push_back(t);
        }
    }
    srand(unsigned(time(NULL)));
    std::random_shuffle(std::begin(deck), std::end(deck));

    std::vector<Tile> opponentHand;
    std::vector<Tile> userHand;
    for (int i = 0; i < 13; i++) {
        opponentHand.push_back(deck.at(0)); 
        deck.erase(deck.begin());
        userHand.push_back(deck.at(0)); 
        deck.erase(deck.begin());
    }
    opponent = new Player(opponentHand);
    realUser = new Player(userHand);
    opponent->sortHand();
    realUser->sortHand();
}

Game::~Game() {
    delete opponent;
    delete realUser;
}

void Game::printDeck() {
    for (int i = 0; i < deck.size(); i++) {
            deck.at(i).printTile();
    }
}

void Game::play() {
    realUser->drawTile(deck.at(0));
    deck.erase(deck.begin());
    realUser->printHand();
}