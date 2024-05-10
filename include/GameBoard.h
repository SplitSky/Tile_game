#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "Tile.h"
#include "utils.h"

class GameBoard {
public:
    std::vector<Tile> tiles;
    std::vector<std::vector<int>> combinations;

    GameBoard();
    void reset();
    bool canAchieveSum(int sum);
    int sumBoard();
    void setCombinations(int target_value);
    bool playTurn()
};

#endif // GAMEBOARD_H
