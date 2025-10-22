/*
 * Author: Timofey Mosagin
 * Email: st142155@student.spbu.ru
 * Project: Assignment 2a
 */

#include <iostream>
#include <fstream>
#include <filesystem>

int main()
{
    std::string infileName;
    std::string outfileName;

    std::cout << "Enter input and output file names: ";
    std::cin >> infileName >> outfileName;

    int size = std::filesystem::file_size(infileName);

    std::ifstream infile;
    infile.open(infileName, std::ios::binary | std::ios::in);

    std::ofstream outfile;
    outfile.open(outfileName, std::ios::binary | std::ios::out);

    char* buffer = new char[size];

    infile.read((char*)&buffer[0], size);

    for (std::size_t i = 0; i < size / 2; i++) {
        char t = buffer[i];
        buffer[i] = buffer[size - i - 1];
        buffer[size - i - 1] = t;
    }

    outfile.write((char*)&buffer[0], size);

    infile.close();
    outfile.close();

    delete[] buffer;

    return 0;
}
