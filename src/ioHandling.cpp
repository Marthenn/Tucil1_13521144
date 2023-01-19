#include "ioHandling.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
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
    int i = 0;
    bool stat = false;
    while(!stat && i<13){
        if(card == validCard[i]){
            stat = true;
        }
        i++;
    }
    return stat;
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

std::vector<int> userInput(){
    bool valid = false;
    std::string input;
    while(!valid){
        std::getline(std::cin, input);
        valid = inputValidation(input);
        if(!valid){
            std::cout << "Masukan tidak sesuai." << std::endl;
        }
    }
    static std::vector<int> cards;
    std::istringstream iss(input);
    for(int i = 0; i < 4; i++){
        iss >> input;
        cards.push_back(convertCard(input));
    }
    return cards;
}

std::vector<int> randomInput(){
    static std::vector<int> cards;
    srand((unsigned) time(NULL));
    for(int i = 0; i < 4; i++){
        cards.push_back(rand() % 13 + 1);
    }
    return cards;
}

void saveToFile(){
    std::ofstream file;
    std::string fileName;
    std::cout<<"Masukkan nama file: ";
    std::cin>>fileName;
    while(fileName.empty()){
        std::cout<<"Nama file tidak boleh kosong."<<std::endl;
        std::cout<<"Masukkan nama file: ";
        std::cin>>fileName;
    }
    fileName = "test/" + fileName;
    file.open(fileName);
    extern std::vector<std::string> solutions;
    if (solutions.size() == 0){
        file << "Tidak ada solusi";
        file << std::endl;
    } else {
        for(auto x: solutions){
            file << x << std::endl;
        }
    }
    file.close();
}