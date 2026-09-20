//
// Created by Emme.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long qpow(long long a, long long b) {
    if (b == 0) return 0;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << n * qpow(4, n - 1) << endl;
    return 0;
}