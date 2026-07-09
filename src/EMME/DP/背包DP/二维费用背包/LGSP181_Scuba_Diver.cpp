//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<int> a(k), b(k), c(k);
        for (int i = 0; i < k; i++) cin >> a[i] >> b[i] >> c[i];
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < k; i++)
            for (int x = m; x >= 0; x--)
                for (int y = n; y >= 0; y--)
                    dp[x][y] = min(dp[x][y], dp[max(0, x - a[i])][max(0, y - b[i])] + c[i]);
        cout << dp[m][n] << endl;
    }
    return 0;
}