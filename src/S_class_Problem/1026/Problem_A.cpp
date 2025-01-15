//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    double a, b, C, S;
    cin >> a >> b;
    if (a > 0 && b > 0 && a != b) {
        C = (a + b) * 2;
        S = a * b;
        printf("%.2lf %.2lf", S, C);
    } else {
        cout << "error";
    }
    return 0;
}