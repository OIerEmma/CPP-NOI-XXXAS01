//
// Created by Geek.Kwok on 2026/9/23.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("g_pow.in", "r", stdin);
    freopen("g_pow.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int a, b, cnt = 0;
    const int INF = 1e9;
    cin >> a >> b;
    long long res = 1;
    while (res <= INF) {
        if (cnt >= b) { cout << res << endl; exit(0); }
        cnt++;
        res *= a;
    }
    cout << "-1" << endl;
    return 0;
}