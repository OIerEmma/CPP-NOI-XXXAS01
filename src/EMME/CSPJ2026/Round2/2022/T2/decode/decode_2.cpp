//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int k;
    cin >> k;
    while (k--) {
        long long n, d, e;
        cin >> n >> d >> e;
        long long m = n - e * d + 2, delta = m * m - 4 * n;
        if (delta < 0) { cout << "NO\n"; continue; }
        long long r = (long long)sqrt((double)delta);
        while (r * r > delta) r--;
        while ((r + 1) * (r + 1) <= delta) r++;
        if (r * r != delta || (m - r) % 2 != 0) { cout << "NO\n"; continue; }
        long long p = (m - r) / 2, q = (m + 2) / 2;
        if (p <= 0) { cout << "NO\n"; continue; }
        cout << p << " " << q << "\n";
    }
    return 0;
}