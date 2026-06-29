//
// Created by Emme.Kwok on 2026/5/17.
//
#include<deque>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = (int)nums.size();
        // 定义状态
        // DP[i] 代表跳到第 i 个位置能得到的最大分数
        vector<int> dp(n + 1, -1e9);
        // 初始条件
        dp[0] = nums[0];
        // 计算顺序
        for (int i = 1; i < n; i++)
            for (int j = i - k; j < i; j++)
                if (j >= 0)
                    dp[i] = max(dp[j] + nums[i], dp[i]); // 状态转移方程
        // 返回结果
        return dp[n - 1];
        /* 分析决策
        ① 有哪些选择？决策允许集合
            · 从 i 跳到 i + j
            · 0 <= j <= k
            · i + j < n
        ② 从哪转移？状态转移过程
            · 对于所有从 0 到 i - 1 的 j
              如果 j + k >= i
              DP[i] = DP[j] + nums[j]
        ③ dp值怎么变？状态计算结果
            · DP[i] = max { DP[j] + nums[j], DP[i],
              0 <= j < i,
              j + k >= i }
        */
    }
    int maxResult2(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> dp;
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!dp.empty() && dq.front() < i - k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            while (!dp.empty() && dq.front() <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};