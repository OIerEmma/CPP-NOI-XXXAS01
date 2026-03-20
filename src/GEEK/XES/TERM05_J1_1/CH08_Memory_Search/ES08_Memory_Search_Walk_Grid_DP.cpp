//
// Created by Geek.Kwok on 2026/3/19.
//
#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
int mp[1005][1005];
int dp[1005][1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int k = mp[i][j];
            if (k == 0) continue; // 不能跳跃，不传播
            // 向下跳
            for (int d = 1; d <= k && i + d <= n; d++) {
                dp[i + d][j] = (dp[i + d][j] + dp[i][j]) % mod;
            }
            // 向右跳
            for (int d = 1; d <= k && j + d <= m; d++) {
                dp[i][j + d] = (dp[i][j + d] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}