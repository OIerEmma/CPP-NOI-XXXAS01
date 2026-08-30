//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        int len = (int)group.size();
        for (int i = 1; i <= len; i++)
            for (int j = n; j >= group[i - 1]; j--)
                for (int k = minProfit; k >= 0; k--)
                    dp[j][k] = (dp[j][k] + dp[j - group[i - 1]][max(0, k - profit[i - 1])]) % MOD;
        return dp[n][minProfit];
    }
};