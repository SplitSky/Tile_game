#include<vector>
#include<algorithm>

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

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end()); // Sort candidates to optimize the process
    std::vector<std::vector<int>> results;
    std::vector<int> currentCombination;
    findCombinations(candidates, target, results, currentCombination, 0);
    return results;
}

// Function to sort vectors within a vector and then sort these vectors by their length
void sortVectors(std::vector<std::vector<int>>& vec, bool ascending = true) {
    // Sort individual vectors
    for (auto& subVec : vec) {
        if (ascending) {
            std::sort(subVec.begin(), subVec.end()); // Sort ascending
        } else {
            std::sort(subVec.rbegin(), subVec.rend()); // Sort descending using reverse iterators
        }
    }

    // Sort the full array based on the length of the individual arrays
    std::sort(vec.begin(), vec.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a.size() < b.size();
    });
}


