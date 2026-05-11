//
// Created by Emme.Kwok on 2026/5/10.
//
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        return dp[n];
    }

    int minCostClimbingStairs2(vector<int>& cost) {
        int n = (int)cost.size();
        vector<int> dp(n + 1, INF);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        return min(dp[n - 1], dp[n - 2]);
    }
};