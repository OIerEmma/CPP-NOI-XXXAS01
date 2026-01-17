//
// Created by Emma on 2025/7/7.
//
#include<iostream>
using namespace std;

double hermite(int n, int x) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2 * x;
    }
    return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

int main() {
    int n, x;
    cin >> n >> x;
    printf("%.2lf\n", hermite(n, x));
    return 0;
}