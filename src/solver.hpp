#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include <string>

extern std::vector<std::string> solutions;

/**
 * @brief This function is used to permute all possible permutations of a vector and then call the solve function for each permutation
 * 
 * @param cards The base vector to be permutated
 */
void permute(std::vector<int> cards, int current, int size);

/**
 * @brief This function is used as a master function to solve the 24 cards game by calling other functions
 * 
 * @param cards Vector of numbers used in the game (will always be valid) 
 * @param expression The current expression that is already calculated
 */
void solve(std::vector<int> cards, std::string expression);

/**
 * @brief This function is used to exhaustively try all possible operations
 * 
 * @param cards Vector of numbers used in the game 
 * @param expression The current expression that is already calculated
 * @param operation Code for the operation to be done between the last two integers
 */
void traverseSolve(std::vector<int> cards, std::string expression, int operation);

#endif