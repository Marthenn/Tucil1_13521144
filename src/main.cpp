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
        std::cout<<"Masukan tidak sesuai."<<std::endl;
        std::cout<<"Apakah ingin memasukkan kartu? (y/n) ";
        std::cin>>input;
        // INPUT HANDLING INI BELUM BENAR KARENA KE DOUBLE KALAU SAMA USER INPUT
    }
    if(input == "y" || input == "Y"){
        std::cout<<"Masukkan 4 kartu (A, 2, 3, ..., 10, J, Q, K) dipisahkan dengan spasi:" << std::endl;
        vec = userInput();
    } else {
        vec = randomInput();
        std::cout<<"Kartu yang dihasilkan: ";
        for(auto x:vec){
            std::cout<<convertInt(x)<<" ";
        }
        std::cout<<std::endl;
    }
    auto start = std::chrono::high_resolution_clock::now();
    permute(vec, 0, 3);
    std::cout<<solutions.size()<<" solutions found"<<std::endl;
    if(solutions.size() == 0){
        std::cout<<"Tidak ada solusi"<<std::endl;
    } else {
        for(auto x:solutions){
            std::cout<<x<<std::endl;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<"Apakah ingin menyimpan hasil ke file? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n" && input != "Y" && input != "N"){
        std::cout<<"Masukan tidak sesuai."<<std::endl;
        std::cout<<"Apakah ingin menyimpan hasil ke file? (y/n) ";
        std::cin>>input;
    }
    if(input == "y" || input == "Y"){
        saveToFile();
    }
    std::cout<<"Waktu eksekusi: "<<duration.count()<<" microseconds"<<std::endl;
    return 0;
}