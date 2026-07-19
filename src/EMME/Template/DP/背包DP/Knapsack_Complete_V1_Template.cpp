//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    // 定义状态：dp[j]代表容量恰好为j时的最优结果
    vector<int> dp(W + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = w[i]; j <= W; j++)
            if (dp[j - w[i]] != INF) dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
    if (dp[W]!= INF) cout << dp[W] << endl;
    else cout << "no solution" << endl;
    return 0;
}