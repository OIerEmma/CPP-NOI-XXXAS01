//
// Created by Amy on 2026/7/19.
//
#include <iostream>
#include <cctype>

int main() {
    char ch;
    std::cin >> ch;
    char upper = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    std::cout << upper << std::endl;
    return 0;
}
