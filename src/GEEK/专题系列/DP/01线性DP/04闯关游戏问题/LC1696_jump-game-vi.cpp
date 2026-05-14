//
// Created by Geek.Kwok on 5/13/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * TODO：该方法会 LTE，需要DP+滑动窗口优化
     */
    int maxResult(vector<int>& nums, int k) {
        // dp[i] 从第i格开始跳转至最后时的最大得分
        int len = nums.size();
        constexpr int NEG_INF = -1e9;
        vector<int> dp(len, NEG_INF);
        dp[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--)
            for (int j = 1; j <= k; j++)
                if (i + j < len)
                    dp[i] = max(dp[i], dp[i + j] + nums[i]);
        return dp[0];
    }
};