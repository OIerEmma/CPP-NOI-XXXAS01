//
// Created by Geek.Kwok on 7/27/26.
// 优化版本：滚动压维，答案正确，scanf 函数版本
//
#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9;
int dp[505][305];
char g[505][505];

int main() {
    int t, n, m, K;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 0; i < n; i++) scanf("%s", g[i]);

        // 定义状态：dp[j][k] 表示到 (i,j) 格子且已修改 k 次的最大得分
        // 初始化起始行 (0,j)
        for (int j = 1; j <= m; j++)
          for (int k = 0; k <= K; k++) dp[j][k] = 0;
        // 计算顺序
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = K; k >= 0; k--) {
                    if (g[i][j-1] == '1') dp[j][k] = max(dp[j][k], dp[j-1][k]) + 1; // max(不改从上边来,不改从左边来) + 1
                    if (g[i][j-1] == '0') dp[j][k] = max(dp[j][k], dp[j-1][k]); // max(不改从上边来,不改从左边来)
                    if (g[i][j-1] == '?') {
                      if (!k) dp[j][k] = max(dp[j][k], dp[j-1][k]);
                      // max(max(不改从上边来, 不改从左边来), max(改从上边来, 改从左边来)+1)
                      else dp[j][k] = max(max(dp[j][k], dp[j-1][k]), max(dp[j][k-1], dp[j-1][k-1]) + 1);
                    }
                }
            }
        }
        // 答案：取终点所有 k 的最大值
        int ans = 0;
        for (int k = 0; k <= K; k++) ans = max(ans, dp[m][k]);
        printf("%d\n", ans);
    }
    return 0;
}