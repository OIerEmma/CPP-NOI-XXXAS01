//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main() {
    // freopen("g_gcd_lcm.in", "r", stdin);
    // freopen("g_gcd_lcm.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    // 设 P=x0*a, Q=x0*b, 则 gcd(a,b)=1 且 lcm(P,Q)=x0*a*b=y0 即 a*b=y0/x0
    // 若 y0%x0 != 0 则答案是0
    // 否则枚举 a*b=k 所有因数对(a,b) 统计gcd(a,b)=1的有序对个数
    int x, y;
    cin >> x >> y;
    if (y % x != 0) { cout << 0 << endl; return 0; }
    int k = y / x, cnt = 0;
    for (int a = 1; a * a <= k; a++) {
        if (k % a) continue;
        int b = k / a;
        if (gcd(a, b) == 1) cnt += (a == b) ? 1 : 2;
    }
    cout << cnt << endl;
    return 0;
}