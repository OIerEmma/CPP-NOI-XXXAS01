//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    printf("%.2lf", round(a / b * 100.0) / 100.0);
    return 0;
}