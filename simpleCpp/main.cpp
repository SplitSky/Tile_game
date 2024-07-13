#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include<random>
#include<numeric>

struct tile {
    bool flipped;
    int value;
    tile(bool flipped_in, int value_in) : flipped(flipped_in), value(value_in) {}
    ~tile() {}
};

std::vector<int> get_values_subvector(const std::vector<tile>& tiles, size_t start_index, size_t end_index) {
    if (start_index > end_index || end_index >= tiles.size() || start_index >= tiles.size()) {
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
    std::cout << "printing all tiles" ;
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
    for (int start_index = 0; start_index < n; ++start_index) {
        int sum = 0;
        for (int end_index = start_index; end_index < n; ++end_index) {
            sum += tiles[end_index].value;
            if (sum == score) {
                results.push_back(get_values_subvector(tiles, start_index, end_index));
                break; // Since the input is sorted, no need to continue once the sum is found
            } else if (sum > score) {
                break; // Since the input is sorted, further elements will only increase the sum
            }
        }
    }
    return results;
}

int calculateRange(const std::vector<int>& list) {
    if (list.empty()) {
        return 0;
    }
    int min_val = *std::min_element(list.begin(), list.end());
    int max_val = *std::max_element(list.begin(), list.end());
    return max_val - min_val;
}

// Function to find the index of the list with the largest range, or largest number if ranges are equal
int chooseLargestRangeGroupIndex(const std::vector<std::vector<int>>& listOfLists) {
    int bestIndex = -1;
    int max_range = -1;
    int max_number = -1;

    for (size_t i = 0; i < listOfLists.size(); ++i) {
        const auto& list = listOfLists[i];
        int current_range = calculateRange(list);
        int current_max_number = list.empty() ? -1 : *std::max_element(list.begin(), list.end());

        if (current_range > max_range || (current_range == max_range && current_max_number > max_number)) {
            max_range = current_range;
            max_number = current_max_number;
            bestIndex = i;
        }
    }

    return bestIndex;
}

int strategyPicker(int type, std::vector<std::vector<int>> combinations) {
  // picks the strategy
  choice = 0
  if (type == 1) {
    // pick a random one
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0,combinations.size());
    choice = distr(gen);
  } else if (type == 2) {
    // pick one where the difference between the two tiles is largest
    choice = chooseLargestRangeGroupIndex(combinations);
    std::cout << "Strat picker" << combinations.size() << " " << choice << std::endl;
  } else if (type == 3) {
    // pick the straegy with the largest number of tiles
    choice = 0;
    int longest = combinations[0].size();
    for (int i{1}; i<combinations.size(); i++) {
      if (combinations[i].size() > longest) {
        choice = i;
      }
    }
  }
  return choice;
}

bool flipStrat1(std::vector<tile> &tiles, int score, int strategy) {
    // flip the first one in the combinations
    std::vector<std::vector<int>> combinations = getCombinations(tiles, score);
    // check the combinations
    if (combinations.empty()) {
        // there are no combinations.
        return false;
    }

    // add function here which returns the index of the combination to use
    int choice = strategyPicker(strategy, combinations); // picks the index of the combination given the strategy
    std::vector<int> combination = combinations[choice]; // picking the strategy
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

void resetBoard(std::vector<tile> &tiles) {
  for (auto &t : tiles) {
    t.flipped = false;
  }
}

int playTurn(std::vector<tile> &tiles, int type) {
    // plays through the entire round until tiles can't be flipped and returns a score
    int roll = rollTwoDice();
    int score = 0;
    bool continue_check = true;
    while (continue_check) { // plays until it can't flip anymore
        continue_check = flipStrat1(tiles, roll, type);  
        std::cout << "The roll = " << roll << std::endl;
        roll = rollTwoDice();
        print_Tiles(tiles);
    }
    score += sumBoard(tiles);
    resetBoard(tiles);
    std::cout << "End Turn!" << std::endl;
    return score;
}

int main() {
    int boardSize = 10;
    int strategy = 1;
    std::vector<tile> tiles;
    int max_rounds = 10;
    for (int i = 1; i < boardSize; ++i) {
        tiles.push_back(tile(false, i));
    }

    //for (int strat{1}; strat <= 3; strat++) {
    int strat = 1;
    std::cout << "Playing with strategy " << strat << std::endl;
    print_Tiles(tiles);
    int temp_score = 0;
    std::vector<int> scores;
    
    for (int i{0}; i<max_rounds; i++) {
      temp_score = playTurn(tiles, strat);
      std::cout << "Score after turn! " << temp_score << std::endl;
      scores.push_back(temp_score);
    }

      // print out all of the scores
    std::cout << "Length of the scores array " << scores.size() << std::endl; 
    int total_score = std::accumulate(scores.begin(), scores.end(), 0);
    std::cout << "Total Score = " << total_score << std::endl;
    //}

    return 0;
}
