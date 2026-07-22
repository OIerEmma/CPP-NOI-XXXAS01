//
// Created by Amy on 2026/6/8.
//
#include<iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int b = x * 87;
    int g = y * 85;
    double a = ( b + g ) * 1.0 / ( x + y );
    printf("%.4lf", a);
    return 0;
}