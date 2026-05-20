 //
// Created by Geek.Kwok on 2026/5/14.
//
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // dp[i] 从第i格开始跳转至最后时的最大得分
        int len = nums.size();
        constexpr int NEG_INF = -1e9;
        vector<int> dp(len, NEG_INF);
        dp[len - 1] = nums[len - 1];
        // 复杂度O(n*k) 10^5 LTE
        // 优化思路：DP + 单调队列
        for (int i = len - 2; i >= 0; i--)
            for (int j = 1; j <= k; j++)
                if (i + j < len)
                    dp[i] = max(dp[i], dp[i + j] + nums[i]);
        return dp[0];
    }

    // 顺序
    int maxResult2(vector<int>& nums, int k) {
        int len = nums.size();
        // dp[i] 到达位置i的最大得分
        vector<int> dp(len, 0);
        dp[0] = nums[0]; // 起点得分就是第一个格子的分数

        // 优化思路：DP + 单调队列
        // 双端队列，存的是下标，起点先排队
        deque<int> dq; dq.push_back(0);
        // 计算顺序
        for (int i = 1; i < len; i++) {
            // 1.踢掉已经离开窗口的人(即下标超出[i-k,i-1])
            while (!dq.empty() && dq.front() < i - k) dq.pop_front();
            // 2.此时队头就是窗口里dp值最大的下标，直接用它来更新dp[i]
            dp[i] = dp[dq.front()] + nums[i];
            // 3.新人dp[i]要排队，把队尾所有dp值小于等于它的都踢走
            while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            // 新人进入队伍
            dq.push_back(i);
        }
        // 返回结果：到达最后一个格子的最大得分
        return dp[len - 1];
    }

    // 逆序
    int maxResult3(vector<int>& nums, int k) {
        int len = nums.size();
        // dp[i] 从i跳到终点的最大得分
        vector<int> dp(len, 0);
        dp[len - 1] = nums[len - 1]; // 终点得分就是最后一个格子的分数

        // 优化思路：DP + 单调队列
        // 双端队列，存的是下标，终点先排队
        deque<int> dq; dq.push_back(len - 1);
        // 计算顺序：逆序
        for (int i = len - 2; i >= 0; i--) {
            // 1.踢掉已经离开窗口的人(即下标超出[i+1,i+k])
            while (!dq.empty() && dq.front() > i + k) dq.pop_front();
            // 2.此时队头就是窗口里dp值最大的下标，直接用它来更新dp[i]
            dp[i] = dp[dq.front()] + nums[i];
            // 3.新人dp[i]要排队，把队尾所有dp值小于等于它的都踢走
            while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            // 新人进入队伍
            dq.push_back(i);
        }
        // 返回结果：起点到终点的最大得分
        return dp[0];
    }
};