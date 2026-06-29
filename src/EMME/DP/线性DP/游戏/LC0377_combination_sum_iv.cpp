//
// Created by Emme.Kwok on 2026/6/19.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= target; j++)
            for (int i = 0; i < n; i++)
                if (j >= nums[i]) dp[j] += dp[j - nums[i]];
        return dp[target];
    }
};

/*
1.划分阶段：这个问题可以划分成哪些阶段？每个阶段在做什么决定？
    针对一个物品，选或不选
2.定义状态：DP[i] 或 DP[i][j] 代表什么？存储的是最大值，最小值，还是方案数？
    DP[i][j] 代表前i个数字，和为j的方案数
3.分析决策
    ① 有哪些选择？决策允许集合：针对第i个物品 选或不选
    ② 从哪转移？状态转移方程：i - 当前物品重量
    ③ dp值怎么变？状态结果计算：
    · 不选：不加
    · 选：加上dp[i - 1][j - a[i]]
4. 状态转移方程
    DP[i][j] += DP[i - 1][j - a[i - 1]]
5.确定初始条件
    DP[0][0 ~ n] = 1;
6.确定计算顺序
    外层从小到大
    内层从小到大
7.确定返回结果 DP[nums.size()][target]
*/