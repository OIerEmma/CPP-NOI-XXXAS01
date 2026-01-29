//
// Created by Emma on 2025/1/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, s = 0, factorial = 1;
    const int MOD = 1000000;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        factorial = factorial * i % MOD;
        s = (factorial + s) % MOD;
    }
    printf ("%d\n", s);
    return 0;
}