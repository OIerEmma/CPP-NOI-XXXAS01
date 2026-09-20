//
// Created by Emme.Kwok on 2026/9/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, s = 0;
    cin >> n;
    while (true) {
        int a = n / 100, b = n / 10 % 10, c = n % 10;
        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (b < c) swap(b, c);
        int m = a * 100 + b * 10 + c - (c * 100 + b * 10 + a);
        if (m != s) cout << a << b << c << "-" << c << b << a << "=" << m << "\n";
        if (m == n) break;
        s = n = m;
    }
    return 0;
}