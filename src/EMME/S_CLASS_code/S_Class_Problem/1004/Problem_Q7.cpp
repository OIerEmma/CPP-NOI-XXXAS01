//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

int a[1000010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 70 == 0) {
            ans += a[i] / 70 * 0.1;
        } else {
            ans += (a[i] / 70 + 1) * 0.1;
        }
    }
    printf("%.1lf\n", ans);
    return 0;
}