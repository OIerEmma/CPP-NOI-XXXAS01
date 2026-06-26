//
// Created by Geek.Kwok on 2026/5/18.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    const int OFFSET = n, MOD = 1e9 + 7;
    // 状态定义：dp[i] 从n开始减少到恰好i的总方案数
    // 初始化
    vector<int> dp(2 * n + 5, 0);
    dp[n + OFFSET] = 1;
    // 计算顺序
    for (int i = n - 1; i > c - max(a, b); i--) {
        if (i + a <= n && i + a > c) dp[i + OFFSET] = (dp[i + OFFSET] + dp[i + a + OFFSET]) % MOD;
        if (i + b <= n && i + b > c) dp[i + OFFSET] = (dp[i + OFFSET] + dp[i + b + OFFSET]) % MOD;
    }
    // 返回结果
    int ans = 0;
    for (int i = c; i > c - max(a, b); i--) ans = (ans + dp[i + OFFSET]) % MOD;
    cout << ans << endl;
    return 0;
}