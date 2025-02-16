//
// Created by Emma on 2025/2/12.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, q = 2, p = 1;
    double ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += q * 1.0 / p;
        const int temp = q + p;
        p = q;
        q = temp;
    }
    printf("%.4lf", ans);
    return 0;
}