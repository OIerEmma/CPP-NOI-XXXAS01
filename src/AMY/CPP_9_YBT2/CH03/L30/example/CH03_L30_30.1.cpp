//
// Created by Amy on 2026/7/9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    double x, n, a;
    cin >> x >> n;
    a = 1.0;
    for (int i = 1; i <= n; i++) a = (a + x / a) / 2;
    printf("%0.3lf", a);
    return 0;
}
