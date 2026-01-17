//
// Created by Emma on 2024/11/18.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char c = 'B';
    putchar(c);
    putchar('\x42');
    putchar(0x42);
    putchar(66);
    return 0;
}