//
// Created by Emme.Kwok on 2026/1/27.
//
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
    freopen("min.in", "r", stdin);
    freopen("min.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int minn = 2 * 1e6 + 1;
        for (int c = a; c <= b; c++) {
            int n = abs(c - a) + abs(b - c);
            if (minn > n) {
                minn = n;
            }
            // cout << n << " " << minn << " " << endl;
        }
        cout << minn << endl;
    }
    return 0;
}