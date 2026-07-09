//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(k), b(k), c(k);
    for (int i = 0; i < k; i++) cin >> a[i] >> b[i] >> c[i];
    // 状态：dp[x][y]代表前若干个气缸氧气至少为x氮气至少为y的最小重量
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < k; i++)
        for (int x = m; x >= 0; x--)
            for (int y = n; y >= 0; y--)
                dp[x][y] = min(dp[max(0, x - a[i])][max(0, y - b[i])] + c[i], dp[x][y]);
    cout << dp[m][n] << endl;
    return 0;
}