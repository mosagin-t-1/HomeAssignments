/*
 * Author: Timofey Mosagin
 * Email: st142155@student.spbu.ru
 * Project: Assignment 1
 */
#include "hello.h"
#include <iostream>
#include <string>

int main() {
    myproject::sayHello("world");

    std::string name;
    while (true) {
        std::cout << "Enter your name (or 'no' to quit): ";
        if (!std::getline(std::cin, name)) break;
        if (name == "no") break;
        myproject::sayHello(name);
    }
    return 0;
}
