//
// Created by Emma on 2025/1/15.
//
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    double xa, xb, ya, yb, a, b, c;
    cin >> xa >> ya >> xb >> yb;
    a = abs(ya - yb);
    b = abs(xa - xb);
    c = sqrt(a * a + b * b);
    printf("%.3lf", c);
    return 0;
}