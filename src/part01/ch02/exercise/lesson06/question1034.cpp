//
// Created by Emma on 2024/11/23.
//
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, a, b, c, c2, c3, p, s;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    a = abs(x1 - x2);
    b = abs(y1 - y2);
    c = sqrt(a * a + b * b);
    a = abs(x1 - x3);
    b = abs(y1 - y3);
    c2 = sqrt(a * a + b * b);
    a = abs(x2 - x3);
    b = abs(y2 - y3);
    c3 = sqrt(a * a + b * b);
    p = (c + c2 + c3) / 2;
    s = sqrt(p * (p - c) * (p - c2) * (p - c3));
    printf("%.2lf", s);
    return 0;
}