//
// Created by Emma on 2025/1/15.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double x, a, b, c, d, s;
    cin >> x >> a >> b >> c >> d;
    s = x * x * x * a + x * x * b + x * c + d;
    printf("%.7lf\n", s);
    return 0;
}