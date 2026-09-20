//
// Created by Emme.Kwok on 2026/9/12.
//
#include <bits/stdc++.h>
using namespace std;

long long qpow(long long a, long long b) {
    if (b == 0) return 1;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool isprime(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i <= x / i; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long h;
        cin >> h;
        if (h == 0) {
            cout << "0\n";
            continue;
        }
        bool flag = false;
        long long a = 1;
        for (int n = 1; a <= h; n++) {
            if (a == h) break;
            if (a - 1 > h) {
                cout << "-1\n";
                flag = true;
                break;
            }
            if (isprime(h - a + 1)) {
                cout << n << '\n';
                flag = true;
                break;
            }
            a *= 2;
        }
        if (!flag) cout << "-1\n";
    }
    return 0;
}