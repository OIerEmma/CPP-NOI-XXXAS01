//
// Created by Geek.Kwok on 2026/5/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 状态定义
        // DP[i][0] 以i为结尾且为正的最长摆动序列长度
        // DP[i][1] 以i为结尾且为负的最长摆动序列长度
        // DP[i][0] = max{DP[j][1]} + 1 ( j < i, nums[i] - nums[j] > 0)
        // DP[i][1] = max{DP[j][0]} + 1 ( j < i, nums[i] - nums[j] < 0)
        // 初始化
        int n = nums.size(), ans0 = 1, ans1 = 1;
        vector<vector<int>> dp(n, vector<int>(2, 1));
        // 计算顺序
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] - nums[j] > 0) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                    dp[i][1] = max(dp[i][1], dp[j][1]);
                } else if (nums[i] - nums[j] < 0) {
                    dp[i][0] = max(dp[i][0], dp[j][0]);
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                } else {
                    dp[i][0] = max(dp[i][0], dp[j][0]);
                    dp[i][1] = max(dp[i][1], dp[j][1]);
                }
            }
            ans0 = max(ans0, dp[i][0]);
            ans1 = max(ans1, dp[i][1]);
        }
        // 返回结果
        return max(ans0, ans1);
    }
};