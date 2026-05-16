//
// Created by Geek.Kwok on 5/12/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // dp[i] 代表从第i个问题开始到最后一个问题，可获得的最高分数
        // 初始化
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // dp[n] = 0 作为越界哨兵

        // 计算顺序
        for (int i = n-1; i >= 0; i--) {
            int points = questions[i][0];
            int brain = questions[i][1];
            int next = i + 1 + brain; // 下一道能做的题（0-based）

            long long skip = dp[i + 1]; // 不做第 i 题
            long long take = points + (next < n ? dp[next] : 0); // 做第 i 题
            dp[i] = max(skip, take);
        }

        // 返回结果
        return dp[0];
    }
};