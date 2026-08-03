//
// Created by Emme.Kwok on 2026/7/23.
//
#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9;
vector<string> g(505);
int dp[505][505][305];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t, n, m, K;
    cin >> t;
    while (t--) {
        cin >> n >> m >> K;
        for (int i = 0; i < n; i++) cin >> g[i];

        // 定义状态：dp[i][j][k] 表示到 (i,j) 格子且已修改 k 次的最大得分
        // 整表先标不可达
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k <= K; k++)
                    dp[i][j][k] = NEG;

        // 初始化起点 (0,0)
        if (g[0][0] == '1') dp[0][0][0] = 1;
        else if (g[0][0] == '0') dp[0][0][0] = 0;
        else { dp[0][0][0] = 0; if (K >= 1) dp[0][0][1] = 1; } // '?' -> '1'

        // 计算顺序：拉取——按字符分支，直接 max(上, 左)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue; // 起点已初始化
                for (int k = 0; k <= K; k++) {
                    if (g[i][j] == '1') {
                        // 无需修改：max(不改从上边来, 不改从左边来) + 1
                        if (i > 0 && dp[i - 1][j][k] != NEG) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + 1);
                        if (j > 0 && dp[i][j - 1][k] != NEG) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + 1);
                    }
                    if (g[i][j] == '0') {
                        // 无需修改：max(不改从上边来, 不改从左边来)
                        if (i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                        if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                    }
                    if (g[i][j] == '?') {
                        // 不修改当前格子：max(不改从上边来, 不改从左边来)
                        if (i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                        if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                        // 修改当前格子：max(改从上边来, 改从左边来) + 1
                        if (k >= 1) {
                            if (i > 0 && dp[i - 1][j][k - 1] != NEG) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + 1);
                            if (j > 0 && dp[i][j - 1][k - 1] != NEG) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + 1);
                        }
                    }
                }
            }
        }

        // 答案：取终点所有 k 的最大值
        int ans = 0;
        for (int k = 0; k <= K; k++) ans = max(ans, dp[n - 1][m - 1][k]);
        cout << ans << endl;
    }
    return 0;
}