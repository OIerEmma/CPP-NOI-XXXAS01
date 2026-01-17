//
// Created by Emma on 2025/3/9.
//
#include<iostream>
using namespace std;

double f(double x, double n) {
    if (n == 1) {
        return x / (1 + x);
    }
    return x / (n + f(x, n - 1));
}

int main() {
    double n, x;
    cin >> x >> n;
    printf("%.2lf\n", f(x, n));
    return 0;
}
