//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int k;
    long long n, d, e;
    cin >> k;
    while (k--) {
        cin >> n >> d >> e;
        long long m = n - e * d + 2, delta = m * m - 4 * n, s = (long long)sqrt(delta);
        if (delta >= 0 && s * s == delta && (m + delta) % 2 == 0 && (m - delta) % 2 == 0)
            cout << (m - s) / 2 << " " << (m + s) / 2 << "\n";
        else cout << "NO\n";
    }
    return 0;
}