//
// Created by Geek.Kwok on 7/1/26.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;
        // 初始化
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        // 顺序
        for (int i = 0; i < n; i++) {
            // 0-1 背包问题：每个硬币只能使用一次
            // for (int k = amount; k >= coins[i]; k--) {
            // 完全背包问题：每个硬币可使用无数次
            for (int k = coins[i]; k <= amount; k++) {
                dp[k] = min(dp[k], dp[k - coins[i]] + 1);
            }
        }
        // 答案
        return dp[amount] == INF ? -1 : dp[amount];
    }
};