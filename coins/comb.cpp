#include <csignal>
#include<iostream>
#include<vector>
#include <unordered_map>
#include <utility>
#include<sstream>
#include<stack>

template <typename T1, typename T2>
// This is a utiliy function used to get a key from two values
std::string pairToString(const std::pair<T1, T2>& p) {
  return std::to_string(p.first) + "," + std::to_string(p.second);
}

// utility function
std::pair<int, int> stringToPair(const std::string& str) {
    std::stringstream ss(str);
    int first, second;
    char comma; // To skip the comma
    // Extract the integers and the comma
    ss >> first >> comma >> second;
    return std::make_pair(first, second);
}

struct cache_table {
    // struct for saving and fetching into cache
    std::unordered_map<std::string, int> table;

    void putIntoCache(int i, int x, int value) {
        std::pair<int,int> p(i,x);
        this->table[pairToString(p)] = value;
    }
    
    bool containsKey(const int i, const int x) {
        // get the key from i and x
        std::pair<int,int> p(i,x);
        std::string key = pairToString(p);
        return this->table.find(key) != this->table.end();
    }

    int fetchFromCache(int i, int x) {
        std::pair<int,int> p(i,x); // return pair matching the cached value
        return this->table[pairToString(p)];
    }

};

struct combinations {
    // stores all of the combinations from the recursive calls
};

int numWaysToMakeAmountX(int i, int x, std::vector<int> &coins, cache_table &table) {
    // check cache
    if (table.containsKey(i, x) == true) {
        // fetch from cache
        return table.fetchFromCache(i, x);
    }
    int take = 0;
    if (i == coins.size()) {
        // base case for recursion relationship that descends on i
        if (x == 0) {
            return 1;
            // NOTE: End state 
        } else {
            return 0;
        }
    }
    if (coins[i] <= x) {
        take = numWaysToMakeAmountX(i, x - coins[i], coins, table);
    }
    int skip = numWaysToMakeAmountX(i + 1, x, coins, table);
    // store cache
    if (take + skip != 0) {
        table.putIntoCache(i, x, take + skip);
    }
    
    return skip + take;
}

int combinations(std::vector<int> coins, int target, cache_table &table) {
    // NOTE: Make this recursive
    // check cache and if not present calculate
    if (table.containsKey(0, target)) {
        return table.fetchFromCache(0, target);
    } else {
        return numWaysToMakeAmountX(0, target, coins, table);
    }
}

int main() { 
  // declare the cache
    cache_table table = cache_table();
    std::vector<int> coins = {1,2,5}; 
    int target = 5;
    std::cout << "The combination count: " << combinations(coins, target, table) << std::endl;
    // print cache table
    for (const auto& pair : table.table) { // print
        std::cout << "Key: " << pair.first << " Value: " << pair.second << std::endl;
    }
}
