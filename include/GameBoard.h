#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "utils.h"

class GameBoard {
public:
    std::vector<int> tiles;
    std::vector<std::vector<int>> combinations;

    GameBoard(int board_size);
    void reset();
    bool canAchieveSum(int sum);
    int sumBoard();
    void setCombinations(int target_value);
    void playTurn(std::function<std::vector<int>(std::vector<int>, int, std::vector<std::vector<int>>)> func); // takes in a strategy and the dice roll and plays the turn
};

#endif // GAMEBOARD_H
