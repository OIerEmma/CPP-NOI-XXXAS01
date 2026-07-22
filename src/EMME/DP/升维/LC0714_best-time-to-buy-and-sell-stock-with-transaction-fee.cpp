//
// Created by Emme.Kwok on 2026/7/22.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        // 0：持有
        // 1：不持有
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = -prices[0], dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }

    int maxProfit2(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        int hold = -prices[0], sold = 0;
        for (int i = 1; i < n; i++) {
            hold = max(hold, sold - prices[i]);
            sold = max(sold, hold + prices[i] - fee);
        }
        return max(hold, sold);
    }
};