#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char** argv){
    std::cout << "Basic Mahjong Game by Audrey Zhou" << std::endl
              << "Enter 'g' to view a guide to the game or 'b' to begin playing." << std::endl;
    bool validInput = false; 
    std::string preStart; 
    std::cin >> preStart;
    while (!validInput) {
        if (preStart == "b" || preStart == "B") {
            std::cout << std::endl << "Starting game..." << std::endl;
            validInput = true;
        }
        else if (preStart == "g" || preStart == "G") {
            std::cout << std::endl << "BASICS:" << std::endl
                      << "You will begin with 13 tiles. Each turn, you obtain one tile and discard one tile from your hand." << std::endl
                      << "The first player to collect 4 triples and 1 pair wins the game." << std::endl << std::endl;
            std::cout << "SUITS:" << std::endl
                      << "There are 3 numbered suits with values ranging from 1 to 9." << std::endl
                      << "These suits are: circles (c), bamboos (b), and thousands (t)." << std::endl
                      << "These will be represented by tiles that look like [c5], [b9], [t1], and so on." << std::endl
                      << "This game also includes 7 special character tiles: [north], [south], [east], [west], [red], [fortune], [blank]" << std::endl
                      << "Each deck has 4 duplicates of different tiles for a total of 4(3*9 + 7) = 136 tiles" << std::endl << std::endl;
            std::cout << "TRIPLES AND PAIRS:" << std::endl
                      << "To make a triple, a player must collect 3 consecutive tiles from the same suit: eg. [c4]+[c6]+[c5]" << std::endl
                      << "A triple may also consist of 3 of the exact same tile: eg. [t9]+[t9]+[t9]" << std::endl
                      << "Different special character tiles cannot form a triple. " << std::endl
                      << "i.e. [red]+[red]+[red] would be a valid triple while [red]+[red]+[east] would not." << std::endl
                      << "To make a pair, a player must collect 2 of the exact same tile: eg. [b2]+[b2] or [red]+[red]" << std::endl << std::endl;
            std::cout << "'PONG' AND 'CHOW':" << std::endl
                      << "You will begin with 13 tiles. Most tiles are obtained by drawing random tiles from the deck." << std::endl
                      << "You can also 'pong' a tile from any player, but you can only 'chow' from the player immediately before you." << std::endl
                      << "If you have a pair and someone discards a 3rd identical tile, you may choose to 'pong' the tile to make a triple." << std::endl
                      << "This new triple will be taken out from your hand and cannot be taken back." << std::endl
                      << "It is now your turn and you must discard a tile." << std::endl
                      << "If the player before you discards a tile that forms a consecutive triple with 2 tiles in your hand, you may 'chow' the tile." << std::endl
                      << "This new triple will also be taken out from your hand and cannot be taken back. You must then discard a tile." << std::endl
                      << "Please note that 'pong' takes precedence over 'chow' if two players attempt to take the same tile." << std::endl << std::endl << std::endl;
            std::cout << "REARRANGING TILES:" << std::endl
                      << "Tiles will not be sorted. You are able to rearrange tiles in your own hand when it is your turn." << std::endl
                      << "To rearrange your tiles, enter 'r' when prompted." << std::endl
                      << "Then enter the indices of the two tiles you would like to switch separated by a space." << std::endl
                      << "i.e. 6 7 to switch the 6th and 7th tiles or 12 13 to switch the 12th and 13th tiles." << std::endl
                      << "This is not necessary to form triples and pairs, but players may find it helpful." << std::endl << std::endl;
            std::cout << "Enter 'b' to begin playing." << std::endl;
            std::cin >> preStart;
        }
        else {
            std::cout << "Input not recognized. Enter 'g' to view a guide to the game or 'b' to begin playing.";
        }
    }
}