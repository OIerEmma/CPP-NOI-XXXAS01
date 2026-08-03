//
// Created by Emme.Kwok on 2026/7/29.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long NEG = -1e9;

    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = (int)prices.size();
        // 定义状态：dp[i][k][0/1] 表示 第i天、第k次卖出、是否持有的最大值
        // 初始化
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(2, NEG)));
        dp[0][0][1] = -prices[0];
        for (int i = 0; i < n; i++) dp[i][0][0] = 0;
        // 顺序
        for (int i = 1; i < n; i++) {
            // 第i天、第0次卖出、持有 = max(第i-1天、第0次卖出、持有, 第i-1天、第0次卖出、不持有 + 买入)
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            // 错误：第i天、第0次卖出、不持有 = max(第i-1天、第0次卖出、不持有, 第i-1天、第0次卖出、持有 + 卖出)
            // dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1] + prices[i]);
            for (int t = 1; t <= k; t++) {
                // 第i天、第t次卖出、持有 = max(第i-1天、第t次卖出、持有, 第i-1天、第t次卖出、不持有 + 买入)
                dp[i][t][1] = max(dp[i - 1][t][1], dp[i - 1][t][0] - prices[i]);
                // 第i天、第t次卖出、不持有 = max(第i-1天、第t次卖出、不持有, 第i-1天、第t-1次卖出、持有 + 卖出)
                dp[i][t][0] = max(dp[i - 1][t][0], dp[i - 1][t - 1][1] + prices[i]);
            }
        }
        // 答案
        long long ans = 0;
        for (int t = 0; t <= k; t++) ans = max(ans, dp[n - 1][t][0]);
        return (int) ans;
    }
};