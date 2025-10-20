// This should be a dynamic programming implementation of the coin flip problem.
// Given an array of numbers  e.x. [1,2,3,4,5]
// give a list of those and the number of combinations that form a target number e.x. 5
// this gives
// 1,1,1,1,1
// 1,1,1,2
// 1,2,2
// etc ...
// using the difference 5 - (sum) == 0
// this comparison lets you produce a cascade using a tree. Stack the value with the largest values first 
// and then allow the candidates to change until you reach the condition. The range and domain of this approach
// need to be clearly defined ot allow for this approach. Solve this problem 
// then implement this using a fixed number of candidates
// Good idea is to change the candidates storage from an array to a dictionary
// {key : value,
//  1 : number of times you can use it,
// }
// This now lets you keep track of how many uses you have and given the present recursion/cascade you can just pass the candidate list until you
// solve the base problem and then zip right back up
// solve the general case first then modify code to fix this

// Example -> coins [1,2,5] and amount = 5
// Combinations are:
// 1,1,1,1,1
// 1,1,1,2
// 1,2,2
// 5
// 
//

Algortihm
1. Sort the coins descending
2. Set i = 0
2. Pick coin c[i]
3. Check if target - coin < 0 : if so i ++
4. If target - coin = 0
    -> add combination
5. If target - coin > 0


function(target, coins)


# Example 2
coins -> [1,4,5,7] and amount = 3
Combinations are: 
1,1,1
# Example 3
coins -> [1,2,3,4,5,6] amount = 7
Combinations are:
1,1,1,1
1,1,2
2,2
1,3
4


//
t = 7
while t - s

dict = {
    1 : 0,
    2 : 0,
    3 : 0,
    4 : 0,
    5 : 0
=======
#include<iostream>
#include<vector>
#include <unordered_map>
#include <utility>
#include <functional>

// Using an array of ints count combinations that sum up to that amount
// amount = 5
// coins = [1,2,5]
// result = [[1,1,1,1,1],[1,1,1,2], [1,2,2],[5]]

int numWaysToMakeAmountX(int i, int x, std::vector<int> &coins) {
    int take = 0;
    if (i == coins.size()) {
        // base case for recursion relationship that descends on i
        if (x == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (coins[i] <= x) {
        take = numWaysToMakeAmountX(i, x - coins[i], coins);
    }
    int skip = numWaysToMakeAmountX(i + 1, x, coins);
    return skip + take;
}

int combinations(std::vector<int> coins, int target) {
    // NOTE: Make this recursive
    return numWaysToMakeAmountX(0, target, coins);
}


int main() { 
    // declare the cache
    std::unordered_map<std::pair<int, int>, std::vector<int>>
    // declare the testing list
}
