//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> m[i];
    // 状态：dp[i]代表前若干种物品，容量不超过i时能得到的最大价值
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int k = 0; k < m[i]; k++)
            for (int j = W; j >= w[i]; j--)
                dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
    cout << dp[W] << endl;
    return 0;
}