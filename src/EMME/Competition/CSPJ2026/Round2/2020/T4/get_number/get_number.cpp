//
// Created by Emme.Kwok on 2026/10/19.
//
#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
long long dp[1005][1005], down[1005], up[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    memset(dp, 0xc0, sizeof dp);
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) dp[i][1] = dp[i - 1][1] + a[i][1];
    for (int j = 2; j <= m; j++) {
        memset(down, 0xc0, sizeof down);
        memset(up, 0xc0, sizeof up);
        for (int i = 1; i <= n; i++) down[i] = max(down[i - 1], dp[i][j - 1]) + a[i][j];
        for (int i = n; i >= 1; i--) up[i] = max(up[i + 1], dp[i][j - 1]) + a[i][j];
        for (int i = 1; i <= n; i++) dp[i][j] = max(down[i], up[i]);
    }
    cout << dp[n][m] << "\n";
    return 0;
}