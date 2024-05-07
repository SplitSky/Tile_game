#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "Tile.h"

class GameBoard {
public:
    std::vector<Tile> tiles;

    GameBoard();
    void reset();
    bool canAchieveSum(int sum);
};

#endif // GAMEBOARD_H
