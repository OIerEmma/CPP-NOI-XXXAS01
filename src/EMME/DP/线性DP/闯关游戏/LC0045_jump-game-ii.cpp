//
// Created by Emme.Kwok on 2026/5/17.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        // 定义状态
        // dp[i] 代表跳到第 i 个位置需要的最小次数
        vector<int> dp(n + 1, 1e9);
        // 初始条件
        dp[0] = 0;
        // 计算顺序
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (j + nums[j] >= i)
                    dp[i] = min(dp[j] + 1, dp[i]); // 状态转移方程
        // 返回结果
        return dp[n - 1];
        /* 分析决策
        ① 有哪些选择？决策允许集合
            · 从 i 跳到 i + j
            · 0 <= j <= nums[i]
            · i + j < n
        ② 从哪转移？状态转移过程
            · 对于所有从 0 到 i - 1 的 j
              如果 j + nums[j] >= i
              dp[i] = dp[j] + 1
        ③ dp值怎么变？状态计算结果
            · dp[i] = max{dp[j] + 1, 0 <= j < i, j + nums[j] >= i}
        */
    }
};