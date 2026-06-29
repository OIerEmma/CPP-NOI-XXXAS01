//
// Created by Emme.Kwok on 2026/5/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        if (n == 1) return questions[0][0]; // 特判案例
        // 状态定义
        // DP[i][0] 前i个问题且第i个问题做的最高分
        // DP[i][1] 前i个问题且第i个问题不做的最高分
        // 预处理：jump_to 表
        vector<vector<int>> jump_to(n + 1);
        for (int next, i = 1; i <= n; i++) {
            next = i + questions[i - 1][1] + 1;
            if (next <= n) jump_to[next].push_back(i);
        }
        // 初始化
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for (int i = 1; i <= n; i++) dp[i][0] = questions[i - 1][0]; // 每个问题自己做可形成的得分
        long long ans0 = dp[1][0], ans1 = dp[1][1];
        // 计算顺序：正序
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + questions[i - 1][0]); // 第i个问题做：前个问题不做的最高得分 + 第i个问题做的得分
            dp[i][1] = max(dp[i][1], dp[i - 1][1]); // 第i个问题不做：前个问题不做的最高得分
            for (int j: jump_to[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + questions[i - 1][0]); // 第i个问题做：所有跳转来源的问题且选择做中取最高得分 + 第i个问题选择做的得分
                dp[i][1] = max(dp[i][1], dp[j][0]); // 第i个问题不做：所有跳转来源的问题且选择做中取最高得分
            }
            ans0 = max(ans0, dp[i][0]);
            ans1 = max(ans1, dp[i][1]);
        }
        // 返回结果
        return max(ans0, ans1);
    }
};