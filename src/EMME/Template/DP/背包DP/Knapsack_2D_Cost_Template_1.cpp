//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // 标准模板（两种资源 ≤ 上限，求 max）
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
    // 状态：dp[i][j]代表前若干个物品，资源1不超过i，资源2不超过j时能得到的最大价值
    for (int i = 0; i < n; i++)
        for (int x = m; x >= a[i]; x--)
            for (int y = k; y >= b[i]; y--)
                dp[x][y] = max(dp[x - a[i]][y - b[i]] + c[i], dp[x][y]);
    cout << dp[m][k] << endl;
    return 0;
}
