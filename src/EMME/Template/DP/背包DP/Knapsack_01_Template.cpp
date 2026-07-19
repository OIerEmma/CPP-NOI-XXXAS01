//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    // 定义状态：dp[j]代表容量不超过j时的最优结果
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
    cout << dp[W] << endl;
    return 0;
}