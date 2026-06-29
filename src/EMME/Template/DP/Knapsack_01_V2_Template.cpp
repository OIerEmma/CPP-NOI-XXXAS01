//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    // 定义状态：dp[i]代表容量至少为i时的最优结果
    vector<int> dp(W + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = W; j >= 0; j--)
            if (dp[max(j - w[i], 0)] != INF) dp[j] = max(dp[max(j - w[i], 0)] + v[i], dp[j]);
    if (dp[W] != INF) cout << dp[W] << endl;
    else cout << "no solution" << endl;
    return 0;
}