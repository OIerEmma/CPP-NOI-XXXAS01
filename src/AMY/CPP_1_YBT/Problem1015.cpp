//
// Created by Amy on 2025/12/20.
//
#include<iostream>
using namespace std;
int main() {
    double r1, r2, r;
    cin >> r1 >> r2;
    r = 1 / (1 / r1 + 1 / r2);
    printf("%0.2f", r);
    return 0;
}