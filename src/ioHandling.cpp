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

int* userInput(){
    bool valid = false;
    std::string input;
    while(!valid){
        std::getline(std::cin, input);
        valid = inputValidation(input);
        if(!valid){
            std::cout << "Masukan tidak sesuai." << std::endl;
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

void saveToFile(int* cards){
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
    // Change this parts later on as the solver (this is just placeholder to test)
    for(int i = 0; i < 4; i++){
        file << convertInt(cards[i]) << " ";
    }
    // End of placeholder
    file << std::endl;
    file.close();
}