//
// Created by Amy on 2026/6/8.
//
#include<iostream>
using namespace std;

int main() {
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    double r = (a * x - b * y) * 1.0 / (a - b);
    printf("%.2lf", r);
    return 0;
}