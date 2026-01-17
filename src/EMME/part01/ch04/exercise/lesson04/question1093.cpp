//
// Created by Emma on 2025/1/5.
//
#include<iostream>
using namespace std;

int main() {
    double x, ans = 0.0;
    int n;
    cin >> x >> n;
    double x2 = 1.0;
    ans += 1;
    for (int i = 1; i <= n; i++) {
        x2 *= x;
        ans += x2;
    }
    printf("%.2lf", ans);
    return 0;
}
