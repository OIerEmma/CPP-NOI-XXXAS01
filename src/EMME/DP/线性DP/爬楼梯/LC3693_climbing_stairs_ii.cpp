//
// Created by Emme.Kwok on 2026/5/10.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (n == 1) return costs[0] + 1;
        vector<int> dp(n + 2, 0);
        dp[0] = 0;
        dp[1] = costs[0] + 1;
        dp[2] = min(dp[1] + costs[1] + 1, costs[1] + 4);
        for (int i = 3; i <= n; i++)
            dp[i] = min(dp[i - 1] + 1, min(dp[i - 2] + 4, dp[i - 3] + 9)) + costs[i - 1];
        return dp[n];
    }
};
/*
1.划分阶段：
2.定义状态：dp[i]代表第 n 级台阶所需的最小总成本
3.分析决策：
    3.1 有哪些选择：从 i 台阶到 i + 1 或 i + 2 或 i + 3
    3.2 从哪转移：从 i - 1、i - 2、i - 3 到台阶 i
    3.3 dp值怎么变：
        - i-1 ~ i: dp[i] = dp[i - 1] + 1 + cost[i]
        - i-2 ~ i: dp[i] = dp[i - 2] + 4 + cost[i]
        - i-3 ~ i: dp[i] = dp[i - 3] + 9 + cost[i]
4.状态转移方程
    dp[i] = min(dp[i - 1] + 1, dp[i - 2] + 4, dp[i - 3] + 9) + cost[i]
5.确定初始条件
    dp[0] = 0;
    dp[1] = dp[0] + cost[0] + 1;
    dp[2] = min(
            dp[0] + costs[1] + 4,
            dp[1] + costs[1] + 1
            );
6.确定计算顺序：从小到大
7.确定返回结果：dp[n]
*/