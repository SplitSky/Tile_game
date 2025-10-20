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
        tile_values.emplace_back(i);
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

std::vector<int> GameBoard::getCandidates() {
    std::vector<int> candidates;
    for (size_t i=0; i < this->tiles.size(); i ++) {
        if (this->tiles[i] == 1) {
            candidates.emplace_back(this->tile_values[i]);
        }
    }
    return candidates;
}

bool GameBoard::canAchieveSum(int sum) {
    // sum is the value that we are trying to achieve
    // Check if sum exceeds the sum of the tiles
    // sorts the array
    int tilesSum = this->sumBoard();
    return tilesSum < sum;
}
////
void GameBoard::playTurn(std::function<std::vector<int>(std::vector<int>, int, std::vector<std::vector<int> >)> func) {
    int diceRoll = rollTwoDice();  // Make sure rollTwoDice() is correctly implemented and accessible
    std::vector<int> tilesToFlip = func(this->tiles, diceRoll, this->combinations);
    // get the not flipped tiles
    std::vector<int> candidates = this->getCandidates();
    
    this->generateCombinations(candidates, diceRoll);
    // Iterate over tiles in combination chosen by the strategy and flip them one by one
    for (int tile_value : tilesToFlip) {
        // Find the tile in the game board and flip it
        auto it = std::find(this->tiles.begin(), this->tiles.end(), tile_value);
        if (it != this->tiles.end()) {
            // Example logic to flip a tile: assuming flipping means setting it to 0 or removing it
            *it = 0;  // or remove it: this->tiles.erase(it);
        } else {
            std::cerr << "Error: Tile value " << tile_value << " not found in the current tiles." << std::endl;
        }
    }
}

////

std::vector<std::vector<int> > GameBoard::generateCombinations(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int> > result;
    std::vector<int> current;
    // Inner recursive function for backtracking
    std::function<void(int, int)> findCombinations = [&](int start, int target) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;  // No need to continue if the number is greater than the remaining target
            if (i > start && candidates[i] == candidates[i-1]) continue;  // Skip duplicates
            current.push_back(candidates[i]);
            findCombinations(i + 1, target - candidates[i]);
            current.pop_back();
        }
    };
    sort(candidates.begin(), candidates.end());  // Sort to facilitate the backtracking process
    findCombinations(0, target);
    this->combinations = result;
}