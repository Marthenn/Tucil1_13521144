#include "ioHandler.hpp"
#include "solver.hpp"

#include <chrono>

int main(){
    std::cout << "Input dari user atau random? (user/random): ";
    std::string input;
    std::cin >> input;
    while(input != "user" && input != "random"){
        std::cout << "Input tidak valid\nInput dari user atau random? (user/random): ";
        std::cin >> input;
    }
    std::vector<int> cards;
    std::cin.ignore(256, '\n');
    if(input == "user"){
        cards = userInput();
    } else {
        cards = randomInput();
        std::cout << "Kartu yang didapat: ";
        for(auto x:cards){
            std::cout << valueToCard(x) << " ";
        }
        std::cout << std::endl;
        std::cout << "Tekan enter untuk melanjutkan...";
        std::cin.get(); 
    }

    auto start = std::chrono::high_resolution_clock::now();
    solve(cards);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = stop - start;

    if(solutions.size() == 0){
        std::cout << "Tidak ada solusi" << std::endl;
    } else {
        std::cout << solutions.size() << " solusi ditemukan" << std::endl;
        for(auto x:solutions){
            std::cout << x << std::endl;
        }
    }

    std::cout << "Waktu eksekusi: " << duration.count() << " ms" << std::endl;

    std::cout << "Apakah ingin menyimpan hasil ke file? (y/n) ";
    std::cin >> input;
    while(input != "y" && input != "n" && input != "Y" && input != "N"){
        std::cout << "Input tidak valid\nApakah ingin menyimpan hasil ke file? (y/n) ";
        std::cin >> input;
    }
    std::cin.ignore(256, '\n');
    if(input == "y" || input == "Y"){
        writeToFile();
    }
    std::cout << "Tekan enter untuk melanjutkan...";
    std::cin.get(); 
    return 0;
}