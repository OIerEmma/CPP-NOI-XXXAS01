//
// Created by Emme.Kwok on 2026/7/5.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = (int)coins.size();
        // 初始化
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        // 顺序
        for (int i = 0; i < n; i++)
            for (int j = coins[i]; j <= amount; j++)
                dp[j] += dp[j - coins[i]];
        // 答案
        return dp[amount];
    }
};