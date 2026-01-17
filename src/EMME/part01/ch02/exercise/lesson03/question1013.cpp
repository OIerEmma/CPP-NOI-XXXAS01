//
// Created by Emma on 2024/11/16.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double c, f;
    cin >> f;
    c = 5 * (f - 32) / 9;
    printf("%.5lf", c);
    return 0;
}