//
// Created by Emme.Kwok on 2026/7/4.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> m[i];
    // 状态：dp[j]代表前若干个物品，容量恰好为j时的最大价值
    // 初始化
    vector<int> dp(W + 1, 0);
    // 顺序
    for (int i = 0; i < n; i++) {
        int c = m[i];
        for (int use, k = 1; c > 0; k <<= 1, c -= use) {
            use = min(k, c);
            int ww = use * w[i], vv = use * v[i];
            for (int j = W; j >= ww; j--)
                dp[j] = max(dp[j], dp[j - ww] + vv);
        }
    }
    // 取答案
    cout << dp[W] << endl;
    return 0;
}