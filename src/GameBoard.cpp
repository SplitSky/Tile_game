#include "GameBoard.h"

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
    // Check if sum exceeds the total of tiles
    return false; // Placeholder
}

void SortTiles(int type) {
    // Creates the copy of the tiles after sorting them
}