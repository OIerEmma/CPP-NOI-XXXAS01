//
// Created by Geek.Kwok on 5/13/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // DP[i] 从第 i 格开始跳转至最后的最少次数
        // 初始化
        int n = nums.size();
        constexpr int INF = 1e9;
        vector<int> dp(n, INF);
        dp[n-1] = 0;
        // 计算顺序
        for (int i = n - 2; i >= 0; i--)
            for(int j = 0; j <= nums[i]; j++)
                if (i + j < n)
                    dp[i] = min(dp[i], dp[i + j] + 1);
        // 返回结果
        return dp[0];
    }
};