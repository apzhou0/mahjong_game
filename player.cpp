#include "player.h"
#include <iostream>
#include <set>
#include <algorithm> 

void Player::printHand() const {
    std::cout << std::endl << "Printing hand" << std::endl;
    for (int i = 0; i < hand.size(); i++) {
        hand.at(i).printTile();
    }
}

void Player::printDiscards() const {
    std::cout << std::endl << "Printing discards" << std::endl;
    for (int i = 0; i < discards.size(); i++) {
        discards.at(i).printTile();
    }
}

void Player::printExposed() const {
    std::cout << std::endl << "Printing exposed" << std::endl;
    for (int i = 0; i < exposed.size(); i++) {
        exposed.at(i).printTile();
    }
}

void Player::sortHand() {
    std::sort(hand.begin(), hand.end());
}

void Player::drawTile(Tile t) {
    std::cout << std::endl << "Drawing tile:" << t.tileToString();
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

bool Player::canPong(Tile t) const {
    int duplicateCount = 0;
    for (int i = 0; i < hand.size(); i++) {
        Tile currTile = hand.at(i);
        if (currTile == t) {
            duplicateCount++;
        }
    }
    return duplicateCount == 2;
}

bool Player::isStraight(Tile t1, Tile t2, Tile t3) const {
    if (t1.getSuit() == 'z' || t2.getSuit() == 'z' || t3.getSuit() == 'z') {
        return false;
    }
    if (!(t1.getSuit() == t2.getSuit() && t2.getSuit() == t3.getSuit())) {
        return false;
    }
    if (t3.getValue() == t2.getValue()+1 && t2.getValue() == t1.getValue()+1) {
        return true;
    }
    return false;
}

bool Player::hasWon() const {
    std::vector<Tile> handCopy = hand;
    std::vector<Tile> triples;
    int tripleCount = 0;
    tripleCount += exposed.size()/3;
    for (int i = 0; i < handCopy.size() - 2; i++) {
        Tile Tile1 = handCopy.at(i);
        Tile Tile2 = handCopy.at(i+1);
        Tile Tile3 = handCopy.at(i+2);
        if ((Tile1 == Tile2 && Tile2 == Tile3) || isStraight(Tile1, Tile2, Tile3)) {
            triples.push_back(Tile1);
            triples.push_back(Tile2);
            triples.push_back(Tile3);
            handCopy.erase(handCopy.begin()+i);
            handCopy.erase(handCopy.begin()+i);
            handCopy.erase(handCopy.begin()+i);
            tripleCount++;
            i = -1;
        }
        if (Tile2 == Tile3) {
            if (i < handCopy.size() - 3) {
                Tile3 = handCopy.at(i+3);
                if ((Tile1 == Tile2 && Tile2 == Tile3) || isStraight(Tile1, Tile2, Tile3)) {
                    triples.push_back(Tile1);
                    triples.push_back(Tile2);
                    triples.push_back(Tile3);
                    handCopy.erase(handCopy.begin()+i);
                    handCopy.erase(handCopy.begin()+i);
                    handCopy.erase(handCopy.begin()+i+1);
                    tripleCount++;
                    i = -1;
                }
            }
        }
    }
    std::cout << std::endl << "Triplecount = " << tripleCount << std::endl;
    for (Tile t : triples) {
        t.printTile();
    }
    std::cout << std::endl << "Handcopy size = " << handCopy.size() << std::endl;
    for (Tile t : handCopy) {
        t.printTile();
    }
    return tripleCount == 4 && handCopy.at(0) == handCopy.at(1);
}

bool Player::pong(Tile t) {
    if (canPong(t)) {
        exposed.push_back(t);
        exposed.push_back(t);
        exposed.push_back(t);
        for (int i = 0; i < hand.size(); i++) {
            if (hand.at(i) == t) {
                hand.erase(hand.begin()+i);
                i--;
            }
        }
    }
    else {
        std::cout << "Unable to pong tile " << t.tileToString() << ".";
        return false;
    }
}

bool Player::chow(Tile t) {
    return false;
}