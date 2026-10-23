//
// Created by Geek.Kwok on 2026/10/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

// a^b mod m（a ≥ 0，b ≥ 0，m ≥ 1）; 要求 m ≤ 约 3e9，保证乘法不溢出 long long
ll qpow(ll a, ll b, ll m) {
    ll r = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

int main() {
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // ...解题...
    return 0;
}