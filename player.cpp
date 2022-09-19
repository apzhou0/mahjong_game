#include "player.h"
#include <iostream>
#include <algorithm> 

void Player::printHand() {
    std::cout << "Printing hand" << std::endl;
    for (int i = 0; i < hand.size(); i++) {
        hand.at(i).printTile();
    }
}

void Player::printDiscards() {
    for (int i = 0; i < hand.size(); i++) {
        discards.at(i).printTile();
    }
}

void Player::printExposed() {
    for (int i = 0; i < hand.size(); i++) {
        exposed.at(i).printTile();
    }
}

void Player::sortHand() {
    std::sort(hand.begin(), hand.end());
}

void Player::drawTile(Tile t) {
    hand.push_back(t);
}

void Player::discard(std::string s) {
    for (int i = 0; i < hand.size(); i++) {
        Tile currTile = hand.at(i);
        if (currTile.tileContent() == s) {
            discards.push_back(currTile);
            hand.erase(hand.begin()+i);
            return;
        }
    }
    std::cout << "Tile not found in hand. Please try again.";
}

bool Player::canPong(Tile t) {
    int duplicateCount = 0;
    for (int i = 0; i < hand.size(); i++) {
        Tile currTile = hand.at(i);
        if (currTile == t) {
            duplicateCount++;
        }
    }
    return duplicateCount == 2;
}

bool Player::canChow(Tile t) {
    return false;
}

bool Player::hasWon() {
    return tripleCount = 4 && hasPair();
}

bool Player::hasPair() {
    return false;
}