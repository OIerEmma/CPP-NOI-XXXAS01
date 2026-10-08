//
// Created by Geek.Kwok on 2026/9/24.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_candy.in", "r", stdin);
    // freopen("g_candy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    // 7 16 23
    // 16 % 7 = 2 ; 23 % 7 = 2 ; 23 - 16 = 7 ;  7 >= 7 则 n - 1 = 6
    // 10 14 18
    // 14 % 10 = 4 ; 18 % 10 = 8 ; 18 - 14 = 4 < 10 则 max(14%10, 18%10)
    // 10 18 22
    int n, L, R;
    cin >> n >> L >> R;
    if (R - L >= n || (L/n + 1) * n <= R) cout << n - 1 << endl;
    else cout << max(L % n, R % n) << endl;
    return 0;
}