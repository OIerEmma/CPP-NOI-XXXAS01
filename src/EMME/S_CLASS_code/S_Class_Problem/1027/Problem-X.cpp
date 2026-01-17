//
// Created by Emma on 2025/1/15.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double a, b, x;
    cin >> a >> b;
    x = b / a * 100;
    printf("%.3lf", x);
    cout << "%";
    return 0;
}