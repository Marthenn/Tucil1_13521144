#include "ioHandling.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <sstream>

const std::string validCard [] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int convertCard(std::string card){
    if(card == "A"){
        return 1;
    } else if(card == "J"){
        return 11;
    } else if(card == "Q"){
        return 12;
    } else if(card == "K"){
        return 13;
    } else {
        return std::stoi(card);
    }
}

std::string convertInt(int card){
    if(card == 1){
        return "A";
    } else if(card == 11){
        return "J";
    } else if(card == 12){
        return "Q";
    } else if(card == 13){
        return "K";
    } else {
        return std::to_string(card);
    }
}

bool cardValidation(std::string card){
    return std::any_of(std::begin(validCard), std::end(validCard), [&](std::string s){return s == card;});
}

bool inputValidation(std::string input){
    std::string card;
    std::istringstream iss(input);
    int count = 0;
    while(iss >> card){
        if(!cardValidation(card)){
            return false;
        }
        count++;
    }
    return count == 4;
}

int* userInput(){
    bool valid = false;
    std::string input;
    while(!valid){
        std::cout << "Enter four cards: ";
        std::getline(std::cin, input);
        valid = inputValidation(input);
        if(!valid){
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
    static int cards[4];
    std::istringstream iss(input);
    for(int i = 0; i < 4; i++){
        iss >> input;
        cards[i] = convertCard(input);
    }
    return cards;
}

int* randomInput(){
    static int cards[4];
    srand((unsigned) time(NULL));
    for(int i = 0; i < 4; i++){
        cards[i] = rand() % 13 + 1;
    }
    return cards;
}