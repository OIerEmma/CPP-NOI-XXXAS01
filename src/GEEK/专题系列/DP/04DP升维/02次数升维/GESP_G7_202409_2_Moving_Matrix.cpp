//
// Created by Geek.Kwok on 7/27/26.
// 标准三维版本
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
        // 初始化起点 (0,0)
        if (g[0][0] == '1') dp[0][0][0] = 1; // '1'
        else if (g[0][0] == '0') dp[0][0][0] = 0; // '0'
        else { dp[0][0][0] = 0; if (K >= 1) dp[0][0][1] = 1; } // '?'
        // 计算顺序
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue; // 起点已初始化
                for (int k = 0; k <= K; k++) {
                    // 从上方或左方转移（不改字符，k 不变）
                    int from_k = NEG;
                    if (i > 0) from_k = max(from_k, dp[i - 1][j][k]);
                    if (j > 0) from_k = max(from_k, dp[i][j - 1][k]);
                    // 从上方或左方转移（修改字符，k-1 变 k）
                    int from_km1 = NEG;
                    if (k >= 1 && i > 0) from_km1 = max(from_km1, dp[i - 1][j][k - 1]);
                    if (k >= 1 && j > 0) from_km1 = max(from_km1, dp[i][j - 1][k - 1]);

                    char c = g[i][j]; int cur = NEG;
                    // 不改当前格子
                    if (from_k != NEG && c == '1') cur = max(cur, from_k + 1);
                    else if (from_k != NEG && c == '0') cur = max(cur, from_k);
                    else if (from_k != NEG && c == '?') cur = max(cur, from_k);
                    // 修改当前格子（只能改 '?' 为 '1'）
                    if (from_km1 != NEG && c == '?' && k >= 1) cur = max(cur, from_km1 + 1);
                    // 状态结果
                    dp[i][j][k] = cur;
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