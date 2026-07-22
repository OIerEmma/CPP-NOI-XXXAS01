//
// Created by Geek.Kwok on 7/22/26.
//
#include <bits/stdc++.h>
using namespace std;

const int MOD = 19650827;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // dp[i][j][0/1] 可组成理想队形的原始队形总数; 0表示最后一个来的是a[i]，1表示最后一个来的是a[j]
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
    for (int i = 1; i <= n; i++) dp[i][i][0] = 1;

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (a[i] < a[i+1]) dp[i][j][0] = (dp[i][j][0] + dp[i+1][j][0]) % MOD;
            if (a[i] < a[j]) dp[i][j][0] = (dp[i][j][0] + dp[i+1][j][1]) % MOD;
            if (a[i] < a[j]) dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][0]) % MOD;
            if (a[j-1] < a[j]) dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][1]) % MOD;
        }

    cout << (dp[1][n][0] + dp[1][n][1]) % MOD << endl;
    return 0;
}