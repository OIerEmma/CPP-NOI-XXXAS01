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
        vector<long long> dp(n + 1, 0);
        dp[n] = 0;
        // 计算顺序
        for (int i = n-1; i >= 0; i--) {
            int next = i + 1 + questions[i][1];
            dp[i] = max(dp[i+1], (next < n ? dp[next] : 0) + questions[i][0]);
        }
        // 返回结果
        return dp[0];
    }
};