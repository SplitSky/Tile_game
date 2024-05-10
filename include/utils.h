#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <algorithm>

void findCombinations(const std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& current, int start);
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
void sortVectors(std::vector<std::vector<int>>& vec, bool ascending);

#endif // UTILS_H
