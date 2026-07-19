//
// Created by Emme.Kwok on 2026/7/18.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> m[i];
    // 状态：dp[i]代表前若干捆物品，容量不超过i时能得到的最大价值
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        int c = m[i];
        for (int use, k = 1; c > 0; k *= 2, c -= use) {
            use = min(k, c);
            int ww = use * w[i], vv = use * v[i];
            for (int j = W; j >= ww; j--)
                dp[j] = max(dp[j - ww] + vv, dp[j]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}