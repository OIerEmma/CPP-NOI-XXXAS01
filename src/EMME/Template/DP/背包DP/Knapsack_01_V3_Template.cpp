//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n), v(n);
    int tot = 0;
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i], tot += v[i];
    // 正常状态：dp[i]代表容量不超过i时的最优结果
    // 反转状态：dp[i]代表道具总攻击力达到i时的最小金币花费
    vector<int> dp(tot + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = tot; j >= v[i]; j--)
            dp[j] = min(dp[j - v[i]] + w[i], dp[j]);
    int ans = 0;
    for (int i = tot; i >= 0; i--) if (dp[i] <= k) { ans = i; break; }
    cout << ans << endl;
    return 0;
}