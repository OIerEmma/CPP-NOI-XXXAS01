//
// Created by Emma on 2024/12/28.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, flag = 1;
    double ans = 0.0, now;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        now = flag * 1.0 / i;
        flag = - flag;
        ans += now;
    }
    printf("%.4lf", ans);
    return 0;
}