#include "player.h"
#include <iostream>
#include <set>
#include <algorithm> 
#include <unistd.h>

std::string Player::name() const {
    if (id == 0) {
        return "You";
    }
    else {
        return "Opponent";
    }
}

void Player::printUser() const {
    std::cout << std::endl << std::endl << "YOUR DISCARDS:";
    printDiscards();
    std::cout << std::endl << "YOUR EXPOSED TRIPLES:";
    printExposed();
    std::cout << std::endl << "YOUR HAND:";
    printHand();
}

void Player::printOpp() const {
    std::cout << std::endl << std::endl << "OPPONENT'S DISCARDS:";
    printDiscards();
    std::cout << std::endl << "OPPONENT'S EXPOSED TRIPLES:";
    printExposed();
    //std::cout << std::endl << "OPPONENT'S HAND:";
    //printHand();
}

void Player::printHand() const {
    std::cout << std::endl;
    for (int i = 0; i < hand.size(); i++) {
        hand.at(i).printTile();
        std::cout << " ";
    }
}

void Player::printDiscards() const {
    std::cout << std::endl;
    for (int i = 0; i < discards.size(); i++) {
        discards.at(i).printTile();
        std::cout << " ";
    }
    if (discards.size() < 1) {
        std::cout << "-";
    }
}

void Player::printExposed() const {
    std::cout << std::endl;
    for (int i = 0; i < exposed.size(); i++) {
        exposed.at(i).printTile();
        if (i == 2 || i == 5 || i == 8 || i == 11) {
            std::cout << " ";
        }
        else {
            std::cout << "+";
        }
    }
    if (exposed.size() < 1) {
        std::cout << "-";
    }
}

void Player::sortHand() {
    std::sort(hand.begin(), hand.end());
}

void Player::drawTile(Tile t) {
    if (name() == "You") {
        std::cout << std::endl << name() << " drew tile " << t.tileToString(); 
    }
    else {
        std::cout << std::endl << std::endl << "Opponent drew a tile from the deck.";
    }
    hand.push_back(t);
    sortHand();
}

bool Player::discard(std::string s) {
    for (int i = 0; i < hand.size(); i++) {
        Tile currTile = hand.at(i);
        if (currTile.tileContent() == s) {
            discards.push_back(currTile);
            hand.erase(hand.begin()+i);
            if (name() == "Opponent") {
                std::cout << std::endl;
            }
            std::cout << std::endl << name() << " discarded tile " << currTile.tileToString(); 
            return true;
        }
    }
    std::cout << "Tile \'" << s << "\' not found in hand. Please double check input and try again.";
    return false; 
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

int Player::winningHand(std::vector<Tile> tiles) const {
    std::vector<Tile> handCopy = tiles;
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
    /*std::cout << std::endl << "Triplecount = " << tripleCount << std::endl;
    for (Tile t : triples) {
        t.printTile();
    }
    std::cout << std::endl << "Handcopy size = " << handCopy.size() << std::endl;
    for (Tile t : handCopy) {
        t.printTile();
    }*/
    if (tripleCount == 4 && handCopy.at(0) == handCopy.at(1)) {
        return 5;
    }
    else {
        return tripleCount;
    }
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

bool Player::canChow(Tile t) const {
    int twoBefore = 0;
    int oneBefore = 0;
    int oneAfter = 0;
    int twoAfter = 0;
    for (int i = 0; i < hand.size(); i++) {
        Tile currTile = hand.at(i);
        if (t.getSuit() == 'z' || currTile.getSuit() == 'z') {
            break;
        }
        if (currTile.getSuit() != t.getSuit()) {
            continue;
        }
        else if (currTile.getValue() == t.getValue() - 2) {
            twoBefore++;
        }
        else if (currTile.getValue() == t.getValue() - 1) {
            oneBefore++;
        }
        else if (currTile.getValue() == t.getValue() + 1) {
            oneAfter++;
        }
        else if (currTile.getValue() == t.getValue() + 2) {
            twoAfter++;
        }
    }
    return (twoBefore > 0 && oneBefore > 0) || (oneBefore > 0 && oneAfter > 0) || (oneAfter > 0 && twoAfter > 0);
}


bool Player::pong(Tile t) {
    int duplicateCount = 0;
    for (int i = 0; i < hand.size(); i++) {
        Tile currTile = hand.at(i);
        if (currTile == t) {
            duplicateCount++;
        }
    }
    int eraseCount = 0;
    if (duplicateCount > 1) {
        exposed.push_back(t);
        exposed.push_back(t);
        exposed.push_back(t);
        for (int i = 0; i < hand.size(); i++) {
            if (hand.at(i) == t && eraseCount != 2) {
                hand.erase(hand.begin()+i);
                i--;
                eraseCount++;
            }
        }
        if (name() == "Opponent") {
            std::cout << std::endl;
        }
        std::cout << std::endl << name() << " pong-ed tile " << t.tileToString();
    }
    else {
        std::cout << "Unable to pong tile " << t.tileToString() << ".";
        return false;
    }
}

bool Player::chow(Tile t) {
    int twoBefore = 0;
    int oneBefore = 0;
    int oneAfter = 0;
    int twoAfter = 0;
    for (int i = 0; i < hand.size(); i++) {
        Tile currTile = hand.at(i);
        if (t.getSuit() == 'z' || currTile.getSuit() == 'z') {
            break;
        }
        if (currTile.getSuit() != t.getSuit()) {
            continue;
        }
        else if (currTile.getValue() == t.getValue() - 2) {
            twoBefore++;
        }
        else if (currTile.getValue() == t.getValue() - 1) {
            oneBefore++;
        }
        else if (currTile.getValue() == t.getValue() + 1) {
            oneAfter++;
        }
        else if (currTile.getValue() == t.getValue() + 2) {
            twoAfter++;
        }
    }
    if (!((twoBefore > 0 && oneBefore > 0) || (oneBefore > 0 && oneAfter > 0) || (oneAfter > 0 && twoAfter > 0))) {
        std::cout << "Unable to chow tile " << t.tileToString() << ".";
        return false;
    }
    Tile temp1('-', 0);
    Tile temp2('-', 0);
    if (twoBefore > 0 && oneBefore > 0) {
        temp1 = Tile(t.getSuit(), t.getValue()-2);
        temp2 = Tile(t.getSuit(), t.getValue()-1);
    }
    else if (oneBefore > 0 && oneAfter > 0) {
        temp1 = Tile(t.getSuit(), t.getValue()-1);
        temp2 = Tile(t.getSuit(), t.getValue()+1);
    }
    else if (oneAfter > 0 && twoAfter > 0) {
        temp1 = Tile(t.getSuit(), t.getValue()+1);
        temp2 = Tile(t.getSuit(), t.getValue()+2);
    }
    exposed.push_back(temp1);
    exposed.push_back(t);
    exposed.push_back(temp2);
    for (int i = 0; i < hand.size(); i++) {
        if (hand.at(i) == temp1) {
            hand.erase(hand.begin()+i);
            break;
        }
    }
    for (int i = 0; i < hand.size(); i++) {
        if (hand.at(i) == temp2) {
            hand.erase(hand.begin()+i);
            break;
        }
    }
    if (name() == "Opponent") {
        std::cout << std::endl;
    }
    std::cout << std::endl << name() << " chow-ed tile " << t.tileToString();
    return true;
}

bool Player::canWin(Tile t) const {
    std::vector<Tile> temp = hand;
    temp.push_back(t);
    return winningHand(temp) == 5;
}

bool Player::moreThanOne(Tile t) const {
    int count = 0; 
    for (int i = 0; i < hand.size(); i++) {
        if (hand.at(i) == t) {
            count++;
        }
    }
    return count > 1;
}

// returns true if tile is drawn from deck
bool Player::playTurn(Tile fromUser, Tile fromDeck) {
    if (canWin(fromUser)) {
        drawTile(fromUser);
        return false;
    }
    if (winningHand(hand) == 4) {
        drawTile(fromDeck);
        if (winningHand(hand) == 5) {
            return true;
        }
        else {
            discard(fromDeck.tileContent());
            return true;
        }
    }
    bool isFromDeck;
    if (canChow(fromUser)) {
        chow(fromUser);
        isFromDeck = false;
    }
    else if (canPong(fromUser)) {
        pong(fromUser);
        isFromDeck = false;
    }
    else {
        drawTile(fromDeck);
        isFromDeck = true;
    }
    // discarding all single character tiles first
    for (Tile t: hand) {
        if (t.getSuit() == 'z' && !moreThanOne(t)) {
            sleep(1);
            discard(t.tileContent());
            return isFromDeck; 
        }
    }
    // discarding edge pieces not part of a double/triple
    for (int i = 0; i < hand.size() - 2; i++) {
        if (isStraight(hand.at(i), hand.at(i+1), hand.at(i+2))) {
            i = i + 2;
        }
        else if (hand.at(i) == hand.at(i+1)) {
            i = i + 1; 
        }
        else if (hand.at(i).getValue() == hand.at(i+1).getValue() - 1) {
            i = i + 1;
        }
        else if (hand.at(i).getSuit() != 'z' && (hand.at(i).getValue() == 1 || hand.at(i).getValue() == 9)) {
            sleep(1);
            discard(hand.at(i).tileContent());
            return isFromDeck; 
        }
    }
    // discarding next tile that isn't part of double/triple
    for (int i = 0; i < hand.size() - 2; i++) {
        if (isStraight(hand.at(i), hand.at(i+1), hand.at(i+2))) {
            i = i + 2;
        }
        else if (hand.at(i) == hand.at(i+1)) {
            i = i + 1; 
        }
        else if (hand.at(i).getValue() == hand.at(i+1).getValue() - 1) {
            i = i + 1;
        }
        else {
            sleep(1);
            discard(hand.at(i).tileContent());
            return isFromDeck;
        }
    }
    sleep(1);
    discard(hand.at(hand.size()-2).tileContent());
}
