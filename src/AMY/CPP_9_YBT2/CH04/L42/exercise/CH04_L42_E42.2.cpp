//
// Created by Amy on 2026/7/22.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double x;
    cin >> x;
    double result;
    if (x < 0) {
        result = -x;
    } else {
        result = x;
    }
    printf("%.2f\n", result);
    return 0;
}
