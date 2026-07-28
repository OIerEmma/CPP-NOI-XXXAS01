//
// Created by Emme.Kwok on 2026/7/23.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // 7.5 * 1e8
    int t;
    cin >> t;
    while (t--) {
        int n, m, K;
        cin >> n >> m >> K;
        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];
        const int NEG = -1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(K + 1, NEG)));
        if (g[0][0] == '1') dp[0][0][0] = 1;
        else if (g[0][0] == '0') dp[0][0][0] = 0;
        else {
            dp[0][0][0] = 0;
            if (K >= 1) dp[0][0][1] = 1;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                for (int k = 0; k <= K; k++) {
                    int from_k = NEG;
                    if (i > 0) from_k = max(from_k, dp[i - 1][j][k]);
                    if (j > 0) from_k = max(from_k, dp[i][j - 1][k]);
                    int from_km1 = NEG;
                    if (k >= 1) {
                        if (i > 0) from_km1 = max(from_km1, dp[i - 1][j][k - 1]);
                        if (j > 0) from_km1 = max(from_km1, dp[i][j - 1][k - 1]);
                    }
                    char c = g[i][j];
                    int cur = NEG;
                    if (from_k != NEG) {
                        if (c == '1') cur = max(cur, from_k + 1);
                        else cur = max(cur, from_k);
                    }
                    if (c == '?' && k >= 1 && from_km1 != NEG)
                        cur = max(cur, from_km1 + 1);
                    dp[i][j][k] = cur;
                }
            }
        int ans = 0;
        for (int i = 0; i <= K; i++)
            ans = max(ans, dp[n - 1][m - 1][i]);
        cout << ans << endl;
    }
    return 0;
}