#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "game.h"

int main(int argc, char** argv){
    std::cout << std::endl << "[M] [A] [H] [J] [O] [N] [G]" << std::endl;
    sleep(1);
    std::cout << "Enter 'g' to view a guide to the game or 'b' to begin playing: ";
    bool validInput = false; 
    std::string preStart; 
    std::cin >> preStart;
    while (!validInput) {
        if (preStart == "b" || preStart == "B") {
            sleep(1);
            std::cout << std::endl << "Starting game..." << std::endl;
            validInput = true;
            sleep(1);
            Game g;
            g.play();
        }
        else if (preStart == "g" || preStart == "G") {
            sleep(1);
            std::cout << std::endl << "_________________________________________";
            std::cout << std::endl << std::endl << "[G] [U] [I] [D] [E]";
            std::cout << std::endl << std::endl << "BASICS:" << std::endl
                      << "You will begin with 13 tiles. Each turn, you obtain one tile and discard one tile from your hand." << std::endl
                      << "The first player to collect 4 triples and 1 pair wins the game." << std::endl << std::endl;
            
            std::cout << "SUITS:" << std::endl
                      << "There are 3 numbered suits with values ranging from 1 to 9." << std::endl
                      << "These suits are: bamboo (b), dot (d), and thousands (t)." << std::endl
                      << "These will be represented by tiles: e.g. [c5], [b9], [t1], etc." << std::endl
                      << "This game also includes 7 special character tiles: north [N], south [S], east [E], west [W], red [R], fortune [F], blank [B]" << std::endl
                      << "The deck has 4 duplicates of each tile for a total of 4(3*9 + 7) = 136 tiles" << std::endl << std::endl;
            
            std::cout << "TRIPLES AND PAIRS:" << std::endl
                      << "To make a triple, a player must collect 3 consecutive tiles from the same suit: e.g. [c4]+[c6]+[c5]" << std::endl
                      << "A triple may also consist of 3 of the exact same tile: e.g. [t9]+[t9]+[t9]" << std::endl
                      << "Different special character tiles cannot form a triple. " << std::endl
                      << "(i.e. [R]+[R]+[R] would be a valid triple while [R]+[R]+[E] would not.)" << std::endl
                      << "To make a pair, a player must collect 2 of the exact same tile: e.g. [b2]+[b2] or [W]+[W]" << std::endl << std::endl;
            
            std::cout << "'PONG' AND 'CHOW':" << std::endl
                      << "Most tiles are obtained by drawing tiles from the deck." << std::endl
                      << "If the other player discards a tile that forms a consecutive triple with 2 tiles in your hand, you may 'chow' the tile." << std::endl
                      << "If you have a pair and the other player discards a 3rd identical tile, you may choose to 'pong' the tile to make a triple." << std::endl
                      << "A triple formed from 'pong' or 'chow' is taken out from your hand and cannot be altered. You must then discard a tile." << std::endl;
            std::cout << "_________________________________________";
            sleep(1);
            std::cout << std::endl << std::endl << std::endl << "Enter 'b' to begin playing: ";
            std::cin >> preStart;
        }
        else {
            std::cout << "Input not recognized. Try again." << std::endl << "Enter 'g' to view a guide to the game or 'b' to begin playing: ";
            std::cin >> preStart;
        }
    }
}