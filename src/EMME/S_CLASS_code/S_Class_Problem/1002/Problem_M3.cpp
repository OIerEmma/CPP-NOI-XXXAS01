//
// Created by Emma on 2025/2/7.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    double num, ans, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &num);
        sum += num;
    }
    ans = sum / n;
    printf("%.4lf", ans);
    return 0;
}