#ifndef IOHANDLER_HPP
#define IOHANDLER_HPP

#include <iostream>
#include <vector>
#include <set>

extern std::set<std::string> solutions;

int cardToValue(std::string card);

std::string valueToCard(int value);

bool inputValidation(std::string input);

bool cardValid(std::string card);

std::vector<int> userInput();

std::vector<int> randomInput();

void writeToFile();

#endif