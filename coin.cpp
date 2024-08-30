// This should be a dynamic programming implementation of the coin flip problem.
// Given an array of numbers  e.x. [1,2,3,4,5]
// give a list of those and the number of combinations that form a target number
// e.x. 5 this gives 1,1,1,1,1 1,1,1,2 1,2,2 etc ... using the difference 5 -
// (sum) == 0 this comparison lets you produce a cascade using a tree. Stack the
// value with the largest values first and then allow the candidates to change
// until you reach the condition. The range and domain of this approach need to
// be clearly defined ot allow for this approach. Solve this problem then
// implement this using a fixed number of candidates Good idea is to change the
// candidates storage from an array to a dictionary {key : value,
//  1 : number of times you can use it,
// }
// This now lets you keep track of how many uses you have and given the present
// recursion/cascade you can just pass the candidate list until you solve the
// base problem and then zip right back up solve the general case first then
// modify code to fix this
// NOTE : You can skip checking if it first. Just calcualte the new target and
// check if that is equal to 0
// NOTE: given a =[5,4,3,2,1] and target = 5
// iteration 1:
// check if 5 fits > Yes > Move > Output : 5
// check if 4 fits > No
//  > Recursion > new target = 1 (5-4)
//    Call the same function again
//    check if 4 fits > No -> Negative
//    check if 3 fits > No -> Negative
//    check if 2 fits > No -> Negative
//    check if 1 fits > Yes > Move > Output : 4,1
// check if 3 fits > No
// > Recursion > new target = 2 (5-3)
//  Call the same function again
//    checj if 3 fits > No
//    check if 2 fits > Yes > Move > Outout : 3,2
// check if 2 fits > No
// > Recursion > new target = 3 (5-2)
//  check if 2 first > No
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

int find_comb(std::vector<int> &coins, int target, size_t curr_index) {
  if (coins.size() == 1) {
    if (target - coins[0] == 0) {
      // NOTE: This checks whether the single coin fits the condtion
      // return the stack as a value
      // TODO: copy the stack onto out scope array
      // Return the stack by reference
    }
  } else {
    // NOTE: This begins the recursion descend.
    //
  }
  return 0;
}
int main() {
  // declare the testing list
  std::vector<int> coins;
  int max_size = 10;
  for (size_t i = 0; i < max_size; i++) {
  }
  int target = 5;
  return 1;
}
