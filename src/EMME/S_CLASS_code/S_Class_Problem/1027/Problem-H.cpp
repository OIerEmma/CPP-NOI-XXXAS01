//
// Created by Emma on 2025/1/15.
//
#include<iostream>
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