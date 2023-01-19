#include "ioHandling.hpp"
#include "solver.hpp"
#include <iostream>
#include <chrono>

int main(){
    extern std::vector<std::string> solutions;
    std::vector<int> vec;
    std::string input;
    std::cout<<"Apakah ingin memasukkan kartu? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n" && input != "Y" && input != "N"){
        std::cout<<"Masukan tidak sesuai"<<std::endl;
        std::cout<<"Apakah ingin memasukkan kartu? (y/n) ";
        std::cin>>input;
    }
    std::cin.ignore(1, '\n');
    if(input == "y" || input == "Y"){
        std::cout<<"Masukkan 4 kartu (A, 2, 3, ..., 10, J, Q, K) dipisahkan dengan spasi:" << std::endl;
        vec = userInput();
    } else {
        vec = randomInput();
        std::cout<<"Kartu yang dihasilkan:\n";
        for(auto x:vec){
            std::cout<<convertInt(x)<<" ";
        }
        std::cout<<std::endl;
    }
    auto start = std::chrono::high_resolution_clock::now();
    permute(vec, 0);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    if(solutions.size() == 0){
        std::cout<<"Tidak ada solusi"<<std::endl;
    } else {
        std::cout<<solutions.size()<<" solusi ditemukan"<<std::endl;
        for(auto x:solutions){
            std::cout<<x<<std::endl;
        }
    }
    std::cout<<"Apakah ingin menyimpan hasil ke file? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n" && input != "Y" && input != "N"){
        std::cout<<"Masukan tidak sesuai"<<std::endl;
        std::cout<<"Apakah ingin menyimpan hasil ke file? (y/n) ";
        std::cin>>input;
    }
    if(input == "y" || input == "Y"){
        saveToFile();
    }
    std::cout<<"Waktu eksekusi: "<<duration.count()<<" ms"<<std::endl;
    return 0;
}