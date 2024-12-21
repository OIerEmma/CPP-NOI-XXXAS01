//
// Created by Emma on 2024/12/21.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n;
    double x, x_ten_of_one;
    cin >> x >> n;
    for (int i = 1; i <= n; i ++) {
        x_ten_of_one = x / 1000;
        x += x_ten_of_one;
    }
    printf("%.4lf", x);
    return 0;
}