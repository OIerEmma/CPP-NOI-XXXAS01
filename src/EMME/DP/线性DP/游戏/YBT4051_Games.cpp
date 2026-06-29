//
// Created by Emme.Kwok on 2026/6/1.
//
#include<iostream>
#include<vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    // DP[i] 代表从 n 变成 i 的总方案数
    vector<int> dp(2 * n + 1, 0);
    const int OFFSET = n;
    // 初始条件
    dp[n + OFFSET] = 1;
    // 计算顺序
    for (int i = n - 1; i > c - max(a, b); i--) {
        // 状态转移方程
        if (i + a > c && i + a <= n) dp[i + OFFSET] = (dp[i + OFFSET] + dp[i + a + OFFSET]) % mod;
        if (i + b > c && i + b <= n) dp[i + OFFSET] = (dp[i + OFFSET] + dp[i + b + OFFSET]) % mod;
    }
    // 计算返回结果
    int ans = 0;
    for (int i = c; i > c - max(a, b); i--) ans = (ans + dp[i + OFFSET]) % mod;
    cout << ans << endl;
    return 0;
}