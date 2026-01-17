//
// Created by Emma on 2024/12/8.
//
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    if (b * b - 4 * a * c < 0) {
        cout << "No answer!";
    } else {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if (fabs(x1 - x2) < 0.0000000001) {
            printf("x1=x2=%.5lf", x1);
        } else {
            if (x1 < x2) {
                printf("x1=%.5lf;x2=%.5lf", x1, x2);
            } else {
                printf("x1=%.5lf;x2=%.5lf", x2, x1);
            }
        }
    }
    return 0;
}