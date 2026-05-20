//
// Created by Emme.Kwok on 2026/5/17.
//
#include<iostream>
#include<vector>
using namespace std;

const int NEG_INF = -1e9;
int n, m;

int main() {
    cin >> n >> m;
    // 定义状态
    // dp[i] 代表前 i 关能获得的最大分数（第i关分数不含）
    vector<int> a(m + 1), b(n + 1), dp(n + 1, NEG_INF);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // 初始条件
    dp[0] = 0;
    // 计算顺序
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++)
            if (i >= a[j]) dp[i] = max(dp[i - a[j]] + b[i - a[j]], dp[i]);
    // for (int i = 0; i <= n; i++) cout << dp[i] << " ";
    // cout << endl;
    int ans = NEG_INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i + a[j] >= n) ans = max(ans, dp[i] + b[i]);
    cout << ans << endl;
    return 0;
}