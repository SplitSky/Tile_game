#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <algorithm>

void findCombinations(const std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& current, int start);
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
void sortVectors(std::vector<std::vector<int>>& vec, bool ascending);
std::vector<int> strategy_1(const std::vector<int> tiles, int target, std::vector<std::vector<int>> combinations);
int rollTwoDice();

#endif // UTILS_H
