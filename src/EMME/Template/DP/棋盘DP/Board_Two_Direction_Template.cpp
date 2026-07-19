//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    // 状态：dp[i][j]代表从[1,1]走到[i,j]的矩阵中，一路走过来的可获得的最大得分
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    cout << dp[n][m] << endl;
    return 0;
}