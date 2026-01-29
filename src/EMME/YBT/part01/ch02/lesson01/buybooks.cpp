//
// Created by Emma on 2024/11/10.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double n = 0, m = 0, c = 0, d = 0;
    cin >> n >> m;
    c = m * 0.8;
    d = n - c;
    printf("%.2lf", d);
    return 0;
}