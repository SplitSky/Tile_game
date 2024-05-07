#include "Tile.h"

Tile::Tile(int val) : value(val), flipped(false) {}

void Tile::flip() {
    flipped = !flipped;
}
