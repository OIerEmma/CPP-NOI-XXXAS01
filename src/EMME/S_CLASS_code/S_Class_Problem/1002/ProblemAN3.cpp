//
// Created by Emma on 2025/2/20.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, sum = 0;
    double ans;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int age;
        cin >> age;
        sum += age;
    }
    ans = sum * 1.0 / n;
    printf("%.2lf", ans);
    return 0;
}