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
  // changed the function to use the transform standard functionality
  // gets a vector of integers between the two indicies but only fetches te value and not the entire tile struct
  // code reviewed: 11/07
  if (start_index > end_index || end_index >= tiles.size()) {
    throw std::out_of_range("Invalid indices for subvector");
  }
  std::vector<int> values;
  values.reserve(end_index - start_index + 1);
  std::transform(tiles.begin() + start_index, tiles.begin() + end_index + 1, std::back_inserter(values), [](const tile& t) {return t.value;});
  return values;
}

void printCombinations(const std::vector<std::vector<int>>& combinations) {
  // builds the string stream and then adds it to the standard output
  // prints the combinations of the tiles generated from generateCombinations function
  // code reviewed: 11/07
  std::cout << "Printing combinations" << std::endl;
  for (const auto& combinations : combinations) {
    std::cout << "[";
    for (size_t j = 0; j < combinations.size(); j++) {
      if (j < combinations.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "], ";
  }
  std::cout << std::endl;
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
  // change the tiles vector to remove the flipped tiles
  std::vector<tile> tiles;
  std::copy_if(tiles_in.begin(), tiles_in.end(), std::back_inserter(tiles), [](const tile& t) {
      return !t.flipped;
  });
  int n = tiles_in.size();
  for (int start_index = 0; start_index < n; ++start_index) {
    int sum = 0;
    for (int end_index = start_index; end_index < n; ++end_index) {
      sum += tiles[end_index].value;
      if (sum == score) {
        results.push_back(get_values_subvector(tiles, start_index, end_index));
        break; // Since the input is sorted, no need to continue once the sum is found
      } else if (sum > score) {
        break; // Since the input is sorted, further elements will only increase the sumBoard
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
                break;
            }
        }
    }
    // terminate after flipping is done with success
    return true;
}

int rollTwoDice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1,6);
    return distr(gen) + distr(gen);
}

int sumBoard(const std::vector<tile> &tiles) { 
  int sum = 0;
  for (const auto& t : tiles) {
    if (t.flipped) {
      sum += t.value;
    }
  }
  return sum;
}
 
void resetBoard(std::vector<tile> &Tiles) {
  for (auto& t : Tiles) {
    t.flipped = false;
  }
}

int playTurn(std::vector<tile> &tiles) {
    // plays through the entire round until tiles can't be flipped and returns a score
    int roll = rollTwoDice();
    int score = 0;
    bool continue_check = true;
    while (continue_check) { // plays until it can't flip anymore
        continue_check = flipStrat1(tiles, roll);  
        roll = rollTwoDice();
        print_Tiles(tiles);
    }
    score += sumBoard(tiles);
    return score;
}

int main() {
    int boardSize = 10;
    std::vector<tile> tiles;
    int max_rounds = 20;
    for (int i = 1; i < boardSize; ++i) {
        tiles.push_back(tile(false, i));
    }
    // board populated
    std::vector<int> scores;
    for (int i{0}; i<max_rounds; i++) {
      scores.push_back(playTurn(tiles));
    }

    // print out all of the scores
    std::cout << "Length of the scores array " << scores.size() << std::endl; 
    return 0;
}
