//
// Created by Amy on 2026/6/8.
//
#include<iostream>
using namespace std;

int main() {
    double a, high, low;
    high = 6 * 9.6 - 5 * 9.4;
    low = 6 * 9.6 - 5 * 9.8;
    a = (6 * 9.6 - high - low) / 4;
    printf("%5.2f", a);
    return 0;
}