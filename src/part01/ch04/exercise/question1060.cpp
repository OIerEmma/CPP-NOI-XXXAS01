//
// Created by Emma on 2024/12/20.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n;
    double ans, num, sum = 0.0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> num;
        sum += num;
    }
    ans = sum * 1.0 / n;
    printf("%.4lf", ans);
    return 0;
}