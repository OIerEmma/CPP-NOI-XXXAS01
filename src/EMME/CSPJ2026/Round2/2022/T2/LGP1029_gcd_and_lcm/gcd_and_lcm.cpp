//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long x, y, ans = 0;
    cin >> x >> y;
    if (x == y) cout << "1\n", exit(0);
    long long n = x * y;
    for (int i = 1; i * i <= n; i++)
        if (gcd(i, n / i) == x && lcm(i, n / i) == y) {
            if (i == n / i) ans++;
            else ans += 2;
        }
    cout << ans << endl;
    return 0;
}