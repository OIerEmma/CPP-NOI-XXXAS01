//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = (int)coins.size();
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = coins[i]; j <= amount; j++)
                if (dp[j - coins[i]] != INF)
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        if (dp[amount] != INF) return dp[amount];
        return -1;
    }
};