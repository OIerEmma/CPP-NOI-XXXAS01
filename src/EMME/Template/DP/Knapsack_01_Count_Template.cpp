//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    // 定义状态：dp[i]代表容量至少为j时的方案数
    vector<int> dp(W + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = (dp[j] + dp[j - w[i]]) % MOD;
    cout << dp[W] << endl;
    return 0;
}