#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include<random>

struct tile {
    bool flipped;
    int value;
    tile(bool flipped_in, int value_in) : flipped(flipped_in), value(value_in) {}
    ~tile() {}
};

std::vector<int> get_values_subvector(const std::vector<tile>& tiles, size_t start_index, size_t end_index) {
    if (start_index > end_index || end_index >= tiles.size()) {
        throw std::out_of_range("Invalid indices for subvector");
    }
    std::vector<int> values;
    values.reserve(end_index - start_index + 1);
    for (size_t i = start_index; i <= end_index; ++i) {
        values.push_back(tiles[i].value);
    }
    return values;
}

void printCombinations(const std::vector<std::vector<int>> &combinations) {
  std::cout << "Printing combinations" << std::endl;
    for (size_t i{0}; i < combinations.size(); i++) {
      std::cout << "[";
      for (size_t j{0}; j < combinations[i].size(); j++) {
        std::cout << combinations[i][j] << ", ";
      }
      std::cout << "], ";
    }
}

void print_Tiles(std::vector<tile> &tiles) {
    std::cout << "[";
    for (size_t i{0}; i<tiles.size(); i++) {
        if (tiles[i].flipped == false) {
            std::cout << tiles[i].value << " ";
        }
    }
    std::cout << "]" << std::endl;
}

std::vector<std::vector<int>> getCombinations(const std::vector<tile>& tiles_in, int score) {
    std::vector<std::vector<int>> results;
    int n = tiles_in.size();
    // change the tiles vector to remove the flipped tiles
    std::vector<tile> tiles;
    std::copy_if(tiles_in.begin(), tiles_in.end(), std::back_inserter(tiles), [](const tile& t) {
        return !t.flipped;
    });
    for (size_t start_index = 0; start_index < n; ++start_index) {
        int sum = 0;
        for (size_t end_index = start_index; end_index < n; ++end_index) {
            sum += tiles[end_index].value;
            if (sum == score) {
                results.push_back(get_values_subvector(tiles, start_index, end_index));
                break; // Since the input is sorted, no need to continue once the sum is found
            } else if (sum > score) {
                break; // Since the input is sorted, further elements will only increase the sum
            }
        }
    }
    printCombinations(results);
    return results;
}

bool flipStrat1(std::vector<tile> &tiles, int score) {
    // flip the first one in the combinations
    std::vector<std::vector<int>> combinations = getCombinations(tiles, score);
    // check the combinations
    if (combinations.empty()) {
        // there are no combinations.
        return false;
    }
    std::vector<int> combination = combinations[0];
    // do the flipping
    for (int number : combination) {
        for (auto& temp_tile : tiles) { // Use a reference to modify the original tile
            if (temp_tile.value == number) {
                temp_tile.flipped = true;
            }
        }
    }
    // terminate after flipping is done with success
    return true;
}

int rollTwoDice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1,6);
    int die1 = distr(gen);
    int die2 = distr(gen);
    return die1 + die2;
}

int sumBoard(std::vector<tile> &tiles) {
    int sum = 0;
    for (size_t i = 0; i<tiles.size(); i++) {
        if (tiles[i].flipped == true) {
            sum += tiles[i].value;
        }
    }
    return sum;
}

int playTurn(std::vector<tile> &tiles) {
    // plays through the entire round until tiles can't be flipped and returns a score
    int roll = rollTwoDice();
    int score = 0;
    bool continue_check = true;
    while (continue_check) { // plays until it can't flip anymore
        continue_check = flipStrat1(tiles, roll);  
        roll = rollTwoDice();
        score += sumBoard(tiles);
        print_Tiles(tiles);
    }
    return score;
}

int main() {
    int boardSize = 10;
    std::vector<tile> tiles;
    for (size_t i = 1; i < boardSize; ++i) {
        tiles.push_back(tile(false, i));
    }
    // board populated
    std::vector<int> scores;
    scores.push_back(playTurn(tiles));
    // print out all of the scores
    std::cout << "Length of the scores array " << scores.size() << std::endl; 
    return 0;
}
