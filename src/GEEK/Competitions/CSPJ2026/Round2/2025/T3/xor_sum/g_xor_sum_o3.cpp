//
// Created by Geek.Kwok on 2026/10/8.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_xor_sum.in", "r", stdin);
    // freopen("g_xor_sum.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n; long long k, ans = 0;
    cin >> n >> k;
    vector<long long> a(n + 1), pre(n + 1);
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    cin >> a[1];
    // pre[1] = a[1];
    if (a[1] == k) dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        // pre[i] = pre[i-1]^a[i];
        if (a[i] == k) dp[i][i] = 1;
    }
    // 状态定义 dp[l][r] 代表 [l,r] 区间内异或和结果等于k的最大个数
    // dp[i][j] = max { dp[i][k] + dp[k+1][j] }, i <= k < j
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            long long val = a[i];
            for (int s = i + 1; s <= j; s++) val ^= a[s];
            // if (pre[i-1] == pre[j]^k) dp[i][j] = 1;
            if (val == k) dp[i][j] = 1;
            for (int s = i; s < j; s++)
                dp[i][j] = max(dp[i][j], dp[i][s] + dp[s+1][j]);
        }
    cout << dp[1][n] << endl;
    return 0;
}