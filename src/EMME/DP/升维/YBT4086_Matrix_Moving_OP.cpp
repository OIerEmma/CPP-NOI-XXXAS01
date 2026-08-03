//
// Created by Emme.Kwok on 2026/7/28.
//
#include<bits/stdc++.h>
using namespace std;

int dp[505][305];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m, K;
    cin >> t;
    while (t--) {
        cin >> n >> m >> K;
        vector<string> g(n);
        // 状态定义：dp[j][k]代表走到(i,j)，使用k次可获得的最大得分
        // 初始化
        for (int i = 0; i < n; i++) cin >> g[i];
        for (int j = 1; j <= m; j++) for (int k = 0; k <= K; k++) dp[j][k] = 0;
        // 计算顺序
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = K; k >= 0; k--) {
                    if (g[i][j - 1] == '1') dp[j][k] = max(dp[j][k], dp[j - 1][k]) + 1;
                    if (g[i][j - 1] == '0') dp[j][k] = max(dp[j][k], dp[j - 1][k]);
                    if (g[i][j - 1] == '?') {
                        if (!k) dp[j][k] = max(dp[j][k], dp[j - 1][k]);
                        else dp[j][k] = max(max(dp[j][k], dp[j - 1][k]), max(dp[j][k - 1], dp[j - 1][k - 1]) + 1);
                    }
                }
        // 取答案
        int ans = 0;
        for (int k = 0; k <= K; k++) ans = max(ans, dp[m][k]);
        cout << ans << endl;
    }
    return 0;
}