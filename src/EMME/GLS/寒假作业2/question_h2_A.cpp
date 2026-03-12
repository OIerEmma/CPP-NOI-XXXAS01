//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if (a > 0 && b > 0) {
        double c = 2 * (a + b), s = a * b;
        printf("%.2lf %.2lf", s, c);
    } else {
        cout << "error";
    }
    return 0;
}