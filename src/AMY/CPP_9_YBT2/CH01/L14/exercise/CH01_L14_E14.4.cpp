//
// Created by Amy on 2026/6/8.
//
#include<iostream>
using namespace std;

int main() {
    double x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    double sum = a * x * x * x + b * x * x + c * x + d;
    printf("%.7lf\n", sum);
    return 0;
}