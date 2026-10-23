//
// Created by Geek.Kwok on 2026/10/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

// 常用上限
// INT_MAX   = 2147483647           （约 2.1e9）
// LLONG_MAX = 9223372036854775807  （约 9.2e18）
const int INF = 0x3f3f3f3f; // 约 1.06e9，两个相加仍不超过 int
const ll LINF = 0x3f3f3f3f3f3f3f3fLL; // 约 4.6e18，两个相加仍不超过 long long

// J22T1 乘方：求 a^b，结果超过 1e9 就输出 -1
ll powerCap(ll a, ll b) {
    const ll LIMIT = 1e9;
    if (a == 1L) return a;
    ll r = 1;
    for (ll i = 1; i <= b; i++) {
        r *= a;
        if (r > LIMIT) return -1;
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