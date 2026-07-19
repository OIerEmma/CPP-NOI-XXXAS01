//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s1(n), s2(m);
    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < m; i++) cin >> s2[i];
    // 状态：dp[i][j]代表s1的前i个数字，s2的前j个数字，最长公共子序列（LCS）的长度
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    cout << dp[n][m] << endl;
    return 0;
}