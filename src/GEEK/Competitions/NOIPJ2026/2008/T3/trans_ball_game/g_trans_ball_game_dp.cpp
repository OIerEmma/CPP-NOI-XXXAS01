//
// Created by Geek.Kwok on 2026/10/22.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 35;
int n, m, dp[MAXN][MAXN];

int main() {
    cin >> n >> m;
    // dp[i][j] 经过i次传递后，到达编号j位置的方案总数
    // dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
    // 初始化
    dp[0][1] = 1;
    // 顺序
    for (int r = 1; r <= m; r++)
        for (int c = 1; c <= n; c++)
            dp[r][c] = dp[r - 1][c - 1 < 1 ? n : c - 1] + dp[r - 1][c + 1 > n ? 1 : c + 1];
    // 答案
    cout << dp[m][1] << endl;
    return 0;
}