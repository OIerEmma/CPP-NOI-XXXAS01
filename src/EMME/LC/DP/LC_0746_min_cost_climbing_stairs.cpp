//
// Created by Emme.Kwok on 2026/5/5.
//
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size(), dp[n + 1];
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i <= n; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        return dp[n];
    }
};