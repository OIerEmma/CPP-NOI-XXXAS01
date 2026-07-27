//
// Created by Geek.Kwok on 7/27/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, K;
    cin >> n >> m >> K;  // K 读入后故意不用 —— 缺信息的标志
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    // 定义状态：dp[i][j] 代表走到 (i,j) 格的最大得分
    // ⚠ 故意不记修改次数：把 ? 一律当成可得 1 分（错误语义，无视 K）
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // 初始化
    if (g[0][0] == '1' || g[0][0] == '?') dp[0][0] = 1;
    else dp[0][0] = 0;
    // 初始化第一行
    for (int j = 1; j < m; j++) {
        int add = 0;
        if (g[0][j] == '1' || g[0][j] == '?') add = 1;
        dp[0][j] = dp[0][j - 1] + add;
    }
    // 初始化第一列
    for (int i = 1; i < n; i++) {
        int add = 0;
        if (g[i][0] == '1' || g[i][0] == '?') add = 1;
        dp[i][0] = dp[i - 1][0] + add;
    }
    // 计算顺序
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int add = 0;
            if (g[i][j] == '1' || g[i][j] == '?') add = 1;
            dp[i][j] = add + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // 答案
    // 迷你样例碰巧也是 1；无法正确表达「不许改 / 最多改 K 次」
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}