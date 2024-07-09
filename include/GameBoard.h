#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "utils.h"

class GameBoard {
public:
    std::vector<int> tiles;
    std::vector<std::vector<int> > combinations;
    std::vector<int> tile_values;

    GameBoard(int board_size);
    void reset();
    bool canAchieveSum(int sum);
    int sumBoard();
    void playTurn(std::function<std::vector<int>(std::vector<int>, int, std::vector<std::vector<int> >)> func); // takes in a strategy and the dice roll and plays the turn
    std::vector<std::vector<int> > generateCombinations(std::vector<int>& candidates, int target);
    std::vector<int> getCandidates();
};

#endif // GAMEBOARD_H
