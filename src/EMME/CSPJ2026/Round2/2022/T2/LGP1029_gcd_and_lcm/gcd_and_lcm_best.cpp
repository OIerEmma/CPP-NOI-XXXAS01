//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    long long x, y, ans = 0;
    cin >> x >> y;
    if (y % x != 0) cout << "0\n", exit(0);
    long long n = y / x;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 && gcd(i, n / i) == 1) {
            if (i == n / i) ans++;
            else ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}