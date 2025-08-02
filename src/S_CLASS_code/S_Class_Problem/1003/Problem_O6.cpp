//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

int a[10];

int main() {
    double ans = 0.0;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    ans += a[0] * 28.9;
    ans += a[1] * 32.7;
    ans += a[2] * 45.6;
    ans += a[3] * 78;
    ans += a[4] * 35;
    ans += a[5] * 86.2;
    ans += a[6] * 27.8;
    ans += a[7] * 43;
    ans += a[8] * 56;
    ans += a[9] * 65;
    cout << ans << endl;
    return 0;
}