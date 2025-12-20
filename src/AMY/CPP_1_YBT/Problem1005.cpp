//
// Created by Amy on 2025/12/20.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> a >> y >> b;
    double z = (double) (b * y * 1 - a * x * 1) / (b - a);
    printf("%0.2f", z);
    return 0;
}