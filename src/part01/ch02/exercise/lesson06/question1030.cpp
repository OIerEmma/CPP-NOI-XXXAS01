//
// Created by Emma on 2024/11/24.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    double r, v;
    cin >> r;
    v = 4.0 / 3 * 3.14 * r * r * r;
    printf("%.2lf", v);
    return 0;
}