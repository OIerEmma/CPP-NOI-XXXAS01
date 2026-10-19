//
// Created by Geek.Kwok on 2026/10/19.
//
#include <bits/stdc++.h>
using namespace std;

const long long NEG_INF = -1e18;
const int MAXN = 1005;
int a[MAXN][MAXN];
long long dp[MAXN][MAXN];
long long down[MAXN], up[MAXN];

int main() {
    // freopen("number.in", "r", stdin); freopen("output.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    // 初始化
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) dp[i][1] = dp[i - 1][1] + a[i][1];
    // 顺序
    for (int j = 2; j <= m; j++) {
        // down[i] 在第i行且方向向下的最大值；向下，来自上一格或从左边刚进来
        down[0] = NEG_INF;
        for (int i = 1; i <= n; i++) down[i] = max(down[i - 1], dp[i][j - 1]) + a[i][j];
        // up[i] 在第i行且方向向上的最大值；向上，来自下一格或从左边刚进来
        up[n + 1] = NEG_INF;
        for (int i = n; i >= 1; i--) up[i] = max(up[i + 1], dp[i][j - 1]) + a[i][j];
        for (int i = 1; i <= n; i++) dp[i][j] = max(down[i], up[i]);
    }
    // 答案
    cout << dp[n][m] << '\n';
    return 0;
}