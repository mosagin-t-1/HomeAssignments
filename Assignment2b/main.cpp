/*
 * Author: Timofey Mosagin
 * Email: st142155@student.spbu.ru
 * Project: Assignment 2b
 */

#include <iostream>
#include <string>
#include <sstream>

int main() {
    double* stack = new double[100];
    double* top = stack - 1;
    std::string input, token;
    std::getline(std::cin, input);
    std::stringstream stream(input);

    while (stream >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double right = *top; top--;
            double left = *top;
            if (token == "+") *top = left + right;
            else if (token == "-") *top = left - right;
            else if (token == "*") *top = left * right;
            else if (token == "/") *top = left / right;
        } else {
            top++;
            *top = std::stod(token);
        }
    }

    std::cout << *top << std::endl;
    delete[] stack;
    return 0;
}

