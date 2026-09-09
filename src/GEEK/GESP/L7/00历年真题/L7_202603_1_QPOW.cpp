//
// Created by Geek.Kwok on 2026/9/9.
//
#include <iostream>
using namespace std;

const long long MOD = 1000000000LL;   // 10^9，不是 10^9+7

long long qpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long ans;
        if (n <= 4) {
            ans = n;                                  // n=1 必须特判
        } else if (n % 3 == 0) {
            ans = qpow(3, n / 3);
        } else if (n % 3 == 1) {
            ans = qpow(3, (n - 4) / 3) * 4 % MOD; // 两个 2，其余是 3
        } else {
            ans = qpow(3, n / 3) * 2 % MOD;       // 一个 2，其余是 3
        }
        cout << ans << endl;
    }
    return 0;
}