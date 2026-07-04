//
// Created by Emme.Kwok on 2026/7/2.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, begin, ml;
    cin >> n >> begin >> ml;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    // 状态：dp[i][j]代表前i首歌是否能变成音量j
    vector<vector<bool>> dp(n + 1, vector<bool>(ml + 1, false));
    dp[0][begin] = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= ml; j++) {
            if (j - c[i] >= 0)
                dp[i + 1][j] = dp[i + 1][j] || dp[i][j - c[i]];
            if (j + c[i] <= ml)
                dp[i + 1][j] = dp[i + 1][j] || dp[i][j + c[i]];
        }
    for (int j = ml; j >= 0; j--) if (dp[n][j]) cout << j << endl, exit(0);
    cout << -1 << endl;
    return 0;
}