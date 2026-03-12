//
// Created by Amy on 2026/3/8.
//
#include<iostream>
using namespace std;

int main() {
    double v, g, m, n, p = 0, q=0;
    cin >> v >> g >> m >> n;
    p = 0.5 * v;
    if (g < 300) {
        q = m;
    }
    if (g >= 300) {
        q = n;
    }
    if (p > q) {
        cout << q;
    }
    if (q > p) {
        cout << p;
    }
    return 0;
}