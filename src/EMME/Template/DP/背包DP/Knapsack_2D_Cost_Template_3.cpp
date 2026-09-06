//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

const long long NEG = -1e18;

int main() {
    // 变体：武器购买（一种资源 ≥ 下限，另一种资源 ≤ 上限，求 min 花费）
    int n, P, Q;
    cin >> n >> P >> Q;
    // 状态：dp[i][j]代表前若干个物品，资源1不小于i，资源2不超过j时能得到的最大价值
    vector<long long> dp(Q + 1, NEG);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        for (int j = Q; j >= c; j--)
            if (dp[j - c] != NEG) dp[j] = max(dp[j], dp[j - c] + p);
    }
    int ans = -1;
    for (int j = 0; j <= Q; j++) if (dp[j] >= P) { ans = j; break; }
    cout << ans << "\n";
    return 0;
}