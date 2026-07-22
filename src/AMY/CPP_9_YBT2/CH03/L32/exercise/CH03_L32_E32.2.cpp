//
// Created by Amy on 2026/7/11.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    double h = 0;
    for (int i = 1; i <= 365; ++i) {
        h += 16.0 / i;
        if (h >= k) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}