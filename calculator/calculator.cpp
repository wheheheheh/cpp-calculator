#include "calculator.h"
#include <cmath>
#include <string>
#include <iostream>

using namespace std::literals;

// переменная для вывода ошибки при вводе неправильного числа
const std::string err_not_num = "Error: Numeric operand expected"s;

// функция для чтения числа и выводе ошибки в случае неправильного ввода
bool ReadNumber(Number& result) {
    if (!(std::cin >> result)) {
        std::cerr << err_not_num << std::endl;
        return false;
    } 
    return true;
}

// основная функция number_1 number_2 числа token - команда
bool RunCalculatorCycle() {
    bool check_memory = false;
    Number memory = 0;
    Number number_1;
    if (!ReadNumber(number_1)) {
        return false;
    }
    std::string token;
    while(std::cin >> token) {
        Number number_2;
        if (token == "+"s) {
            if (!ReadNumber(number_2)) {
                return false;
            }
            number_1 += number_2;
        } else if (token == "-"s) {
            if (!ReadNumber(number_2)) {
                return false;
            }
            number_1 -= number_2;
        } else if (token == "*"s) {
            if (!ReadNumber(number_2)) {
                return false;
            }
            number_1 *= number_2;
        } else if (token == "/"s) {
            if (!ReadNumber(number_2)) {
                return false;
            }
            number_1 /= number_2;
        } else if (token == "**"s) {
            if (!ReadNumber(number_2)) {
                return false;
            }
            number_1 = std::pow(number_1, number_2);
        } else if (token == "="s) {
            std::cout << number_1 << std::endl;
        } else if (token == "c"s) {
            number_1 = 0;
        } else if (token == ":"s) {
            if (!ReadNumber(number_2)) {
                return false;
            }
            number_1 = number_2;
        } else if (token == "q"s) {
            return true;
        } else if (token == "s"s) {
            memory = number_1;
            check_memory = true;
        } else if (token == "l"s) {
            if (!check_memory) {
                std::cerr << "Error: Memory is empty"s << std::endl;
                return false;
            }
            number_1 = memory;
        } else {
            std::cerr << "Error: Unknown token "s << token << std::endl;
            return false;
        }
    }
    return true;
}