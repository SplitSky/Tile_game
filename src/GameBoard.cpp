#include "GameBoard.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "utils.h"
#include <functional>

GameBoard::GameBoard() {
    for (int i = 1; i <= 9; ++i) {
        tiles.emplace_back(i);
    }
}

void GameBoard::reset() {
    for (auto& tile : tiles) {
        tile.flipped = false;
    }
}

bool GameBoard::canAchieveSum(int sum) {
    // Check if sum exceeds the sum of the tiles
    std::vector<int> temp_board = {};
    // sorts the array
    int tilesSum = 0;
    for (Tile tile_temp: tiles) {
        tilesSum += tile_temp.value;
    }
    return tilesSum >= sum;
}

void GameBoard::setCombinations(int target_value) {
    // saves the combinations of the allowed tiles into the variable combinations
    std::vector<int> values = {};
    for (Tile tile_temp : tiles) {
        values.emplace_back(tile_temp.value);
    }
    this->combinations = combinationSum(values, target_value);
}

void playTurn(GameBoard& board, int diceRoll, std::function<std::vector<int>(const GameBoard&, int)> strategy) {
    std::vector<int> tilesToFlip = strategy(board, diceRoll);
    if (board.canFlip(tilesToFlip)) {
        board.flipTiles(tilesToFlip);
        std::cout << "Flipped tiles: ";
        for (int tile : tilesToFlip) std::cout << tile << " ";
        std::cout << std::endl;
    } else {
        std::cout << "Cannot flip the chosen tiles." << std::endl;
    }
    board.printBoard();
}
