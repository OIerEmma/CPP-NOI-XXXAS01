//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    // 状态：dp[i][j]代表从1到i行，1到j列的矩阵中，最大的所有数值都为1的正方形的边长
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1, a; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a;
            if (a == 1) dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            ans = max(ans, dp[i][j]);
        }
    cout << ans << endl;
    return 0;
}