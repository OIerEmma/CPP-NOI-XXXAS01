//
// Created by Emma on 2025/2/7.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double x;
    int n;
    cin >> x >> n;
    for (int i = 1; i <= n; i++) {
        x += x / 100 * 0.1;
    }
    printf("%.4f", x);
    return 0;
}