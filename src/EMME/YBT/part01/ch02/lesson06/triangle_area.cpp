//
// Created by Emma on 2024/11/23.
//
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    double a, b, c;
    scanf("%lf%lf%lf",&a, &b, &c);
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%0.3lf\n", s);
    return 0;
}