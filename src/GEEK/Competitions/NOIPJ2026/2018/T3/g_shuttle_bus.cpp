//
// Created by Geek.Kwok on 2026/10/11.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_shuttle_bus.in", "r", stdin);
    // freopen("g_shuttle_bus.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    const int INF = 1e9;
    int n, m, maxt = 0;
    cin >> n >> m;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i], maxt = max(maxt, t[i]);
    sort(t.begin(), t.end());
    // dp[i][j] 前i个人最后1次摆渡车出发时刻为j时的所有同学等车时间之和最小值
    vector<vector<int>> dp(n, vector<int>(maxt + 1, INF));
    // 初始化
    for (int j = 0; j <= maxt; j++) if (t[0] <= j) dp[0][j] = j - t[0];
    // 调试
    // for (int j = 0; j <= maxt; j++) cout << dp[0][j] << " "; cout << endl;
    // 顺序
    for (int i = 1; i < n; i++) {
        for (int j = t[i]; j <= maxt; j++) {
            dp[i][j] = dp[i - 1][j] + j - t[i]; // 与前1次的发车一起出发
            // cout << dp[i][j] << " ";
            if (j >= m) dp[i][j] = min(dp[i][j], dp[i - 1][j - m] + j - t[i]); // 自己单独出发
            // cout << dp[i][j] << " | ";
        }
        // 找出当前人的最小时间和作为下一次的起点
    }
    // 调试
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= maxt; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // 答案
    int ans = INF;
    for (int j = 0; j <= maxt; j++) ans = min(ans, dp[n - 1][j]);
    cout << ans << endl;
    return 0;
}