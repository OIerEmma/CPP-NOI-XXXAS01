//
// Created by Emma on 2024/11/23.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    double a, b, r;
    int k;
    cin >> a >> b;
    k = int(a / b);
    r = a - k * b;
    cout << r;
    return 0;
}