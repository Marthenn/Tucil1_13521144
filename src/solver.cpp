#include "ioHandler.hpp"
#include "solver.hpp"

extern std::set<std::string> solutions;

const char ops[] = {'+', '-', '*', '/'};

bool compare(float a, float b){
    return (a-b < 0.0001 && a-b > -0.0001);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(std::vector<int> vec, int current){
    if(current == vec.size()){
        std::string solution = "";
        for(int i = 0; i < vec.size(); i++){
            solution += valueToCard(vec[i]);
        }
        brute(vec);
    }

    for(int i = current; i < vec.size(); i++){
        swap(&vec[current], &vec[i]);
        permute(vec, current + 1);
        swap(&vec[current], &vec[i]);
    }
}

float calculate(float a, float b, char op){
    if(op == '+'){
        return a+b;
    }
    if(op == '-'){
        return a-b;
    }
    if(op == '*'){
        return a*b;
    }
    if(op == '/'){
        return a/b;
    }
    return 0;
}

void solve(std::vector<int> cards){
    permute(cards, 0);
}

void brute(std::vector<int> cards){
    for(auto op1: ops){
        for(auto op2: ops){
            for(auto op3: ops){

                // (((a b) c) d)
                if(compare(calculate(calculate(calculate(cards[0], cards[1], op1), cards[2], op2), cards[3], op3), 24.0f)){
                    solutions.insert("(((" + valueToCard(cards[0]) + op1 + valueToCard(cards[1]) + ")" + op2 + valueToCard(cards[2]) + ")" + op3 + valueToCard(cards[3]) + ")");
                }

                // ((a (b c)) d)
                if(compare(calculate(calculate(cards[0], calculate(cards[1], cards[2], op2), op1), cards[3], op3), 24.0f)){
                    solutions.insert("((" + valueToCard(cards[0]) + op1 + "(" + valueToCard(cards[1]) + op2 + valueToCard(cards[2]) + "))" + op3 + valueToCard(cards[3]) + ")");
                }

                // (a ((b c) d)
                if(compare(calculate(cards[0], calculate(calculate(cards[1], cards[2], op2), cards[3], op3), op1), 24.0f)){
                    solutions.insert("(" + valueToCard(cards[0]) + op1 + "((" + valueToCard(cards[1]) + op2 + valueToCard(cards[2]) + ")" + op3 + valueToCard(cards[3]) + "))");
                }

                // (a (b (cd)))
                if(compare(calculate(cards[0], calculate(cards[1], calculate(cards[2], cards[3], op3), op2), op1), 24.0f)){
                    solutions.insert("(" + valueToCard(cards[0]) + op1 + "(" + valueToCard(cards[1]) + op2 + "(" + valueToCard(cards[2]) + op3 + valueToCard(cards[3]) + ")))");
                }

                // ((ab) (cd))
                if(compare(calculate(calculate(cards[0], cards[1], op1), calculate(cards[2], cards[3], op3), op2), 24.0f)){
                    solutions.insert("((" + valueToCard(cards[0]) + op1 + valueToCard(cards[1]) + ")" + op2 + "(" + valueToCard(cards[2]) + op3 + valueToCard(cards[3]) + "))");
                }

            }
        }
    }
}