//
// Created by Geek.Kwok on 5/12/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // dp[i] 走到第 i 题面前时的最大得分 i 属于 [0, n]
        // 初始化
        vector<long long> dp(n + 1, 0);
        // 计算顺序
        for (int i = 0; i < n; i++) {
            int points = questions[i][0];
            int brain = questions[i][1];

            // 不做第i题：把当前分数传给下一题
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // 做第i题：把当前分数 + 本题分数传给跳到的位置
            int next = i + brain + 1;
            if (next > n) next = n; // 跳出考试了就记录在终点
            dp[next] = max(dp[next], dp[i] + points);
        }
        // 返回结果
        return dp[n];
    }
};