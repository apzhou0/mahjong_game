#include <iostream>
#include <algorithm> 
#include <random> 
#include <unistd.h>
#include <chrono>
#include "game.h"

Game::Game() {
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
    realUser = new Player(userHand, 0);
    opponent = new Player(opponentHand, 1);
    realUser->sortHand();
    opponent->sortHand();
}

Game::~Game() {
    delete opponent;
    delete realUser;
}

void Game::printDeck() {
    std::cout << std::endl;
    for (int i = 0; i < deck.size(); i++) {
            deck.at(i).printTile();
    }
}

bool Game::gameOver() {
    if (realUser->winningHand(realUser->hand) == 5) {
        sleep(1);
        std::cout << std::endl << std::endl << "GAME OVER: YOU WON!";
        std::cout << std::endl << "Winning Hand:"; 
        realUser->printHand();
        return true;
    }
    else if (opponent->winningHand(opponent->hand) == 5) {
        sleep(1);
        std::cout << std::endl <<  std::endl << "GAME OVER: OPPONENT WINS!";
        std::cout << std::endl << "Winning Hand:"; 
        opponent->printHand();
        return true;
    }
    return false;
}

void Game::play() {
    std::string userInput;
    bool validInput;
    realUser->drawTile(deck.at(0));
    deck.erase(deck.begin());
    realUser->printUser();
    while (!gameOver() && deck.size() != 0) {
        validInput = false;
        while (!validInput) {
            std::cout << std::endl << std::endl << "Enter card to discard (e.g. 'd8') : ";
            std::cin >> userInput;
            sleep(1);
            if (realUser->discard(userInput)) {
                validInput = true;
            }
        }
        validInput = false;
        sleep(1);
        if (opponent->playTurn(realUser->discards.back(), deck.at(0))) {
            deck.erase(deck.begin());
        }
        else {
            realUser->discards.pop_back();
        }
        if (gameOver()) {
            break;
        }
        sleep(1);
        opponent->printOpp(); 
        realUser->printUser();
        while (!validInput) {
            std::cout << std::endl << std::endl << "Enter 'c' to chow " << opponent->discards.back().tileToString() 
            << ", 'p' to pong " << opponent->discards.back().tileToString() << ", or 'd' to draw from deck : ";
            std::cin >> userInput; 
            if (userInput == "c") {
                sleep(1);
                validInput = realUser->chow(opponent->discards.back());
                
                if (validInput) {
                    opponent->discards.pop_back();
                }
            }
            else if (userInput == "p") {
                sleep(1);
                validInput = realUser->pong(opponent->discards.back());
                if (validInput) {
                    opponent->discards.pop_back();
                }
            }
            else if (userInput == "d") {
                sleep(1);
                realUser->drawTile(deck.at(0));
                deck.erase(deck.begin());
                validInput = true;
            }
            else {
                std::cout << "Please double check your input and try again. ";
            }
        }
        realUser->printUser();
    }
    if (deck.size() == 0) {
        sleep(1);
        std::cout << std::endl << std::endl << "GAME OVER: DRAW." << std::endl << "No tiles left in deck. ";
    }
}