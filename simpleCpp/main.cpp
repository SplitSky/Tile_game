#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>

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

std::vector<std::vector<int>> getCombinations(const std::vector<tile>& tiles, int score) {
    std::vector<std::vector<int>> results;
    int n = tiles.size();

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



int main() {
    int boardSize = 10;
    std::vector<tile> tiles;
    for (size_t i = 1; i < boardSize; ++i) {
        tiles.push_back(tile(false, i));
    }
    // board populated

    // initialize the loop for a single combination flipping
    int target_score = 6;
    if (flipStrat1(tiles, target_score)) {
        std::cout << "Flipping was successful." << std::endl;
    } else {
        std::cout << "No combination found for the target score." << std::endl;
    }

    // Print the state of tiles
    for (const auto& t : tiles) {
        std::cout << "Value: " << t.value << ", Flipped: " << (t.flipped ? "true" : "false") << std::endl;
    }

    return 0;
}
