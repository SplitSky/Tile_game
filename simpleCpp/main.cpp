#include<iostream>
#include<vector>
#include <algorithm>
#include <functional>

struct tile {
    bool flipped;
    int value;
    tile(bool flipped_in, int value_in) : flipped(flipped_in), value(value_in) {};
    ~tile() {};
};

std::vector<std::vector<int>> getCombinations(std::vector<tile> &tiles, int score) {
    // implement using backtracking or functional programming TODO
}



bool flipStrat1(std::vector<tile> &tiles, int score) {
    // flip the first one in the combinations
    std::vector<std::vector<int>> combinations = getCombinations(tiles, score);
    // check the combinations
    if (tiles.size() == 0) {
        // there are no combinations.
        return false;
    }
    std::vector<int> combination = combinations[0];
    // do the flipping
    for (int number : combination) {
        for (tile temp_tile : tiles) {
            if (temp_tile.value == number) {
                temp_tile.flipped = true;
            }
        }
    }
    // terminate after flipping is done with success
    return true;
}


int main() {
    int boardSize = 10;
    std::vector<tile> tiles;
    for (size_t i=1; i<boardSize; i++) {
        tiles.push_back(tile(false, i));
    }
    // board populated

    // initialise the loop for a single combination flipping



}

