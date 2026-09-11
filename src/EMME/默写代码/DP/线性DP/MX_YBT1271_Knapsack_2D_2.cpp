//
// Created by Emme.Kwok on 2026/9/11.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int m, n;
    cin >> m >> n;
    int k;
    cin >> k;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    while (k--) {
        int x, y, w;
        cin >> x >> y >> w;
        for (int i = m; i >= 0; i--)
            for (int j = n; j >= 0; j--)
                dp[i][j] = min(dp[i][j], dp[max(i - x, 0)][max(j - y, 0)] + w);
    }
    cout << dp[m][n] << endl;
    return 0;
}