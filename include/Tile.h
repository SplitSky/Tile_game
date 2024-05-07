#ifndef TILE_H
#define TILE_H

class Tile {
public:
    int value;
    bool flipped;

    Tile(int val);
    void flip();
};

#endif // TILE_H
