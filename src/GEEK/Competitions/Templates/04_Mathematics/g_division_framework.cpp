//
// Created by Geek.Kwok on 2026/10/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

// 正数向上取整 (a + b - 1) / b; 负数取模 ((x % m) + m) % m; 乘法、加法边算边取模

// 向上取整（a ≥ 0，b > 0）：N16T1 买铅笔，需要几包
ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}

// 负数取模：C++ 中 -7 % 3 = -1，要变成 2
ll modPos(ll x, ll m) {
    return (x % m + m) % m;
}

// J21T1 分糖果：k 取 [L, R] 中的整数，求 k mod n 的最大值
ll maxMod(ll n, ll L, ll R) {
    if (L / n < R / n) return n - 1; // 区间跨过了 n 的倍数，能取到余数 n-1
    return R % n; // 在同一段内，余数随 k 递增，取 R
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