#include <iostream>
#include "tile.h"

std::string Tile::tileContent() const {
    std::string converted = "";
    if (suit != 'z') {
        converted = suit + std::to_string(value);
    }
    else if (value == 1) {
        converted = "N";
    }
    else if (value == 2) {
        converted = "S";
    }
    else if (value == 3) {
        converted = "E";
    }
    else if (value == 4) {
        converted = "W";
    }
    else if (value == 5) {
        converted = "R";
    }
    else if (value == 6) {
        converted = "F";
    }
    else if (value == 7) {
        converted = "B";
    }
    return converted;
}

std::string Tile::tileToString() const {
    return "[" + tileContent() + "]";
}

void Tile::printTile() const { 
    std::cout << tileToString(); 
}

bool Tile::operator==(const Tile &t) const {
    return suit == t.suit && value == t.value;
}

bool Tile::operator<(const Tile &t) const {
    if (this->suit == t.suit) {
        return value < t.value;
    }
    return this->suit < t.suit;
}
