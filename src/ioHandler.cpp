#include "ioHandler.hpp"

#include <sstream>
#include <fstream>

std::set<std::string> solutions;

const std::string validCard[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int cardToValue(std::string card){
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

std::string valueToCard(int value){
    if(value == 1){
        return "A";
    } else if(value == 11){
        return "J";
    } else if(value == 12){
        return "Q";
    } else if(value == 13){
        return "K";
    } else {
        return std::to_string(value);
    }
}

bool inputValidation(std::string input){
    std::stringstream ss(input);
    std::string card;
    int count = 0;
    while(ss >> card){
        if(!cardValid(card)){
            return false;
        }
        count++;
    }
    if(count != 4){
        return false;
    }
    return true;
}

bool cardValid(std::string card){
    for(int i = 0; i < 13; i++){
        if(card == validCard[i]){
            return true;
        }
    }
    return false;
}

std::vector<int> userInput(){
    std::cout << "Masukkan 4 kartu: ";
    std::string input;
    std::getline(std::cin, input);
    while(!inputValidation(input)){
        std::cout << "Input tidak valid\nMasukkan 4 kartu: ";
        std::getline(std::cin, input);
    }
    std::stringstream ss(input);
    std::string card;
    std::vector<int> cards;
    while(ss >> card){
        cards.push_back(cardToValue(card));
    }
    return cards;
}

std::vector<int> randomInput(){
    std::vector<int> cards;
    for(int i = 0; i < 4; i++){
        cards.push_back(rand() % 13);
    }
    return cards;
}

void writeToFile(){
    std::ofstream file;
    std::string fileName;
    std::cout << "Masukkan nama file: ";
    std::getline(std::cin, fileName);
    file.open(fileName);
    if(!file.is_open()){
        std::cout << "File tidak dapat diakses" << std::endl;
        return;
    }
    if(solutions.empty()){
        std::cout << "Tidak ada solusi" << std::endl;
        return;
    }
    for (auto i = solutions.begin(); i != solutions.end(); i++){
        file << *i << std::endl;
    }
    file.close();
    std::cout << "Solusi berhasil disimpan ke file " << fileName << std::endl;
}