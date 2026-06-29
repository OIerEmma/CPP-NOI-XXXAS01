//
// Created by Geek.Kwok on 2026/5/12.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, 0);

        // 不偷第1家
        // 初始化
        dp[0] = 0, dp[1] = 0;
        // 计算顺序
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        // 返回结果 DP[n]
        const int ans = dp[n];

        // 不偷最后1家
        // 初始化
        dp[0] = 0, dp[1] = nums[0];
        // 计算顺序
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        // 返回结果 DP[n - 1]
        return max(ans, dp[n - 1]);
    }
};