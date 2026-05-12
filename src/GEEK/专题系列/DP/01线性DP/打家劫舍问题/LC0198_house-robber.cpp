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
        // 初始化
        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = nums[0];
        // 计算顺序
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        // 返回结果
        return dp[n];
    }
};