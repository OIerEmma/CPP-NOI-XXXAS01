//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        ans += a * (b * 1.0 / 10);
    }
    printf("%.2lf\n", ans);
    return 0;
}