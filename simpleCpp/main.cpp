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
std::vector<int> get_values_subvector(const std::vector<tile>& tiles, size_t start_index, size_t end_index) {
    // Ensure the indices are within bounds and valid
    if (start_index > end_index || end_index >= tiles.size()) {
        throw std::out_of_range("Invalid indices for subvector");
    }
    std::vector<int> values;
    values.reserve(end_index - start_index + 1); // Reserve space to avoid reallocations
    // Extract the values from the specified range
    for (size_t i = start_index; i <= end_index; ++i) {
        values.push_back(tiles[i].value);
    }
    return values;
}

std::vector<std::vector<int>> getCombinations(std::vector<tile> &tiles, int score) {
    // implement using backtracking or functional programming TODO
    std::vector<std::vector<int>> results;
    int sum = 0;
    for (size_t curr_index = 0; curr_index < tiles.size(); curr_index++) {
        sum = tiles[curr_index].value;
        for (size_t start_sum_index = curr_index+1; start_sum_index < tiles.size(); start_sum_index++) {
            sum += tiles[start_sum_index].value;
            if (sum == score) {
                results.push_back(get_values_subvector(tiles, curr_index, start_sum_index)); // returns the subvector of the values
            }
        }
        sum = 0;
    }
    return results;
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

