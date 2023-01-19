#include "solver.hpp"
#include "ioHandling.hpp"
#include <iostream>

std::vector<std::string> solutions;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void permute(std::vector<int> vec, int current){
    if(current == 3){
        solve(vec, "");
    }

    for(int i = current; i<=3; i++){
        swap(vec[current], vec[i]);
        permute(vec, current + 1);
        swap(vec[current], vec[i]);
    }
}

void solve(std::vector<int> cards, std::string expression){
    if(cards.size() == 1){
        if(cards[0] == 24){
            solutions.push_back(expression);
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        traverseSolve(cards, expression, i);
    }
}

void traverseSolve(std::vector<int> cards, std::string expression, int operation){
    int num1 = cards.back(); cards.pop_back();
    int num2 = cards.back(); cards.pop_back();
    int num3;
    char operation_symbols[] = {'+', '-', '*', '/'};
    switch(operation){
        case 0:
            num3 = num1 + num2;
            break;
        case 1:
            num3 = num1 - num2;
            break;
        case 2:
            num3 = num1 * num2;
            break;
        case 3:
            if (num2 == 0) return;
            if (num1 % num2 != 0) return;
            num3 = num1 / num2;
            break;
        default:
            break;
    }
    cards.push_back(num3);
    if(expression == ""){
        expression = convertInt(num1);
    }
    expression = "(" + expression + " " + operation_symbols[operation] + " " + convertInt(num2) + ")";
    solve(cards, expression);
}