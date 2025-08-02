//
// Created by Emma on 2025/7/7.
//
#include<iostream>
#include<cmath>
using namespace std;

double f(double x, double n) {
    if (n == 1) {
        return sqrt(1 + x);
    }
    return sqrt(n + f(x, n - 1));
}

int main() {
    double x, n;
    cin >> x >> n;
    printf("%.2lf\n", f(x, n));
    return 0;
}