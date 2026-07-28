//
// Created by Emme.Kwok on 2026/7/23.
//
#include <bits/stdc++.h>
using namespace std;

int dp[510][310], dp2[510][310];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, K;
        cin >> n >> m >> K;
        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];

        const int NEG = -1e9;
        // dp[j][k] : 当前行第 j 列，使用 k 次修改的最高得分
        memset(dp, 0xc0, sizeof dp);

        // 初始化起点 (0,0)
        if (g[0][0] == '1') dp[0][0] = 1;
        else if (g[0][0] == '0') dp[0][0] = 0;
        else { dp[0][0] = 0; if (K >= 1) dp[0][1] = 1; } // '?'

        // ---------- 动态规划 ----------
        for (int i = 0; i < n; i++) {
            // 上一行，仅 i>0 时有效
            if (i > 0) {
                int **prev_row = dp;                     // 保存上一行
                memset(dp, 0xc0, sizeof dp);  // 重置
            }

            // 第一行已初始化 j=0，所以从 j=1 开始；其他行从 j=0 开始
            int start_j = (i == 0) ? 1 : 0;
            for (int j = start_j; j < m; j++) {
                for (int k = 0; k <= K; k++) {
                    // 不修改，k 不变
                    int from_k = NEG;
                    if (i > 0) from_k = max(from_k, prev_row[j][k]); // 上方
                    if (j > 0) from_k = max(from_k, dp[j - 1][k]);   // 左方
                    // 用一次修改，k-1 -> k
                    int from_km1 = NEG;
                    if (k >= 1) {
                        if (i > 0) from_km1 = max(from_km1, prev_row[j][k - 1]);
                        if (j > 0) from_km1 = max(from_km1, dp[j - 1][k - 1]);
                    }

                    char c = g[i][j];
                    int cur = NEG;
                    // 不改当前格子
                    if (from_k != NEG) {
                        if (c == '1') cur = max(cur, from_k + 1);
                        else if (c == '0') cur = max(cur, from_k);
                        else if (c == '?') cur = max(cur, from_k);
                    }
                    // 修改当前格子（只能把 '?' 改成 '1'）
                    if (c == '?' && k >= 1 && from_km1 != NEG)
                        cur = max(cur, from_km1 + 1);

                    dp[j][k] = cur;
                }
            }
        }

        // 取终点所有 k 的最大值
        int ans = 0;
        for (int k = 0; k <= K; k++)
            ans = max(ans, dp[m - 1][k]);
        cout << ans << endl;
    }
    return 0;
}