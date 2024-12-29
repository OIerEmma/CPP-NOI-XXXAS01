//
// Created by Emma on 2024/12/27.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, q = 2, p = 1, temp;
    double ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += q * 1.0 / p;
        temp = q + p;
        p = q;
        q = temp;
    }
    printf("%.4lf", ans);
    return 0;
}