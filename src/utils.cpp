#include<vector>
#include<algorithm>
#include<random>

void findCombinations(const std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& current, int start) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
        current.push_back(candidates[i]);
        // Recursive call with updated target and starting index
        findCombinations(candidates, target - candidates[i], result, current, i); // Allow repeated use of same element
        current.pop_back(); // Backtrack
    }
}

int rollTwoDice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1,6);
    int die1 = distr(gen);
    int die2 = distr(gen);
    return die1 + die2;
}

std::vector<int> strategy_1(std::vector<int> tiles, int target, std::vector<std::vector<int>> combinations) {
    // given a board state it takes the tiles that contain the largest number
    // sort the tiles from biggest to smallest
    return combinations[0];
}

std::vector<int> strategy_2(std::vector<int> tiles, int target, std::vector<std::vector<int>> combinations) {
    // given a board state it takes the tiles that contain the largest number
    // sort the tiles from biggest to smallest
    return combinations[combinations.size()-1];
}

std::vector<int> strategy_3(std::vector<int> tiles, int target, std::vector<std::vector<int>> combinations) {
    // This strategy relies on flipping as many tiles as possible.
    return combinations[combinations.size()-1];
}

std::vector<int> strategy_4(std::vector<int> tiles, int target, std::vector<std::vector<int>> combinations) {
    // this strategy picks random combinations
    int arraySize = combinations.size();
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, arraySize - 1);
    // return the random choice
    return combinations[distr(eng)];
}
