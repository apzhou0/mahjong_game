#include <iostream>
#include <string>
#include <cstdlib>
#include "tile.h"
#include "player.h"
#include "game.h"

#include <algorithm>
#include <vector>
#include <set>

int main(int argc, char** argv){
    Game g;
    g.play();
    /*std::vector<Tile> testHand;
    testHand.push_back(Tile('b', 4));
    testHand.push_back(Tile('b', 5));
    testHand.push_back(Tile('b', 6));
    testHand.push_back(Tile('b', 4));
    testHand.push_back(Tile('b', 5));
    testHand.push_back(Tile('b', 6));

    testHand.push_back(Tile('z', 4));
    testHand.push_back(Tile('z', 4));
    testHand.push_back(Tile('z', 4));

    testHand.push_back(Tile('d', 4));
    testHand.push_back(Tile('d', 4));
    testHand.push_back(Tile('d', 4));

    testHand.push_back(Tile('z', 2));
    testHand.push_back(Tile('z', 2));


    Player *p = new Player(testHand);
    p->sortHand();
    p->printHand();
    std::cout << std::endl << p->hasWon();*/
}