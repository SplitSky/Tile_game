#include "GameBoard.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "utils.h"
#include <functional>

/*
Represent tiles as a vector
[1,1,1,1,1,1,1,1,0]
The index+1 = value
1 = not flipped
0 = flipped
*/

GameBoard::GameBoard(int board_size) {
    for (int i = 1; i <= board_size; ++i) {
        tiles.emplace_back(1);
    }
}

int GameBoard::sumBoard() {
    // Sum the board unflipped tiles. The sum of the tiles available
    int total = 0;
    for (size_t i=0; i<tiles.size(); i++) {
        total += (i+1)*tiles[i];
    }
    return total;
}

void GameBoard::reset() {
    for (auto& tile : tiles) {
        tile = 0;
    }
}

bool GameBoard::canAchieveSum(int sum) {
    // Check if sum exceeds the sum of the tiles
    std::vector<int> temp_board = {};
    // sorts the array
    int tilesSum = 0;
    for (size_t i = 0; i <= tiles.size(); i ++) {
        tilesSum += (i+1)*tiles[i];
    }
    return tilesSum >= sum;
}

void GameBoard::setCombinations(int target_value) {
    // saves the combinations of the allowed tiles into the variable combinations
    std::vector<int> values = {};
    for (size_t i=0; i <= tiles.size(); i++) {
        values.emplace_back(i+1);
    }
    this->combinations = combinationSum(values, target_value);
    // this function does the processing of the possible moves. The strategy section only picks the tile to pick from this list
}

void GameBoard::playTurn(std::function<std::vector<int>(std::vector<int>, int, std::vector<std::vector<int>>)> func) {
    int diceRoll = rollTwoDice();
    std::vector<int> tilesToFlip = func(this->tiles, diceRoll, this->combinations);
    // generates only the allowed tiles given the game state and possible combinations
    for (int tile_value : tilesToFlip) {
        // iterates over tiles in combination chosen by the strategy
        // flips them one by one
        
    }
}