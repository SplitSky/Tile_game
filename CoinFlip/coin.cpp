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
