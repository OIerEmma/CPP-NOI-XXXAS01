//
// Created by Emme.Kwok on 2026/7/2.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e8;

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] %= f;
    // 状态：dp[i][j]代表前i头牛组成能力为j的小队的方案数
    vector<vector<int>> dp(n + 1, vector<int>(f + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < f; j++)
            dp[i + 1][j] = (dp[i][j] + dp[i][((j - a[i]) % f + f) % f]) % MOD;
    cout << dp[n][0] - 1 << endl;
    return 0;
}