//
// Created by Emme.Kwok on 2026/7/1.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int coins[4] = {1, 5, 10, 25};
const int amount = 36;

int main() {
    // 状态：dp[i]代表凑成金额恰好为i时所需的最少金币数
    // 初始化
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    // 顺序
    for (int i = 0; i < 4; i++)
        for (int j = coins[i]; j <= amount; j++)
            dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
    // 答案
    if (dp[amount] != INF) cout << dp[amount] << endl;
    else cout << "no solution" << endl;
    return 0;
}