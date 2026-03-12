//
// Created by Emma on 2025/2/22.
//
#include<iostream>
#include<cmath>
using namespace std;

double cal(double number) {
    if (number < 1) {
        return 0.0;
    }
    if (number <= 70) {
        return 0.1;
    }
    double a = number / 70;
    return ceil(a) * 0.1;
}

int main() {
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum = sum + cal(a);
    }
    printf("%.1lf", sum);
    return 1;
}
