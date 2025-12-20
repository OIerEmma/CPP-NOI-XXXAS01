//
// Created by Amy on 2025/12/20.
//
#include<iostream>
using namespace std;
int main() {
    int q,s;
    double n;
    cin >> q >> s;
    n = s * 1.0 / q * 100;
    printf("%0.3f%%",n);
    return 0;
}