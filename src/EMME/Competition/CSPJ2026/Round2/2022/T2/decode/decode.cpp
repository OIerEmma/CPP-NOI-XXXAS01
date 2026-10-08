//
// Created by Emme.Kwok on 2026/9/30.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    long long n, d, e;
    int k;
    cin >> k;
    while (k--) {
        cin >> n >> d >> e;
        long long m = n + 2 - d * e, delta = m * m - 4 * n, s = (long long)sqrt(delta);
        if (delta >= 0 && s * s == delta && (m + s) % 2 == 0 && (m - s) % 2 == 0)
            cout << (m - s) / 2 << " " << (m + s) / 2 << "\n";
        else cout << "NO\n";
    }
    return 0;
}