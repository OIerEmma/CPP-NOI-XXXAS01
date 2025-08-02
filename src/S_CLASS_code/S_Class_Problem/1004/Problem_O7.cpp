//
// Created by Emma on 2025/7/6.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double pi = 0.0;
    for (int i = 1; ; i++) {
        double x = pow(1.0 / sqrt(3), 2 * i - 1) / (2 * i - 1);
        if (x < 1e-6) {
            break;
        }
        pi += x * pow(-1, i + 1);
    }
    printf("%.10lf\n", pi * 6);
    return 0;
}