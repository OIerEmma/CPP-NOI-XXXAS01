//
// Created by Emma on 2024/11/16.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double r1, r2, R;
    cin >> r1 >> r2;
    R = 1 / (1 / r1 + 1 / r2);
    printf("%.2lf", R);
    return 0;
}