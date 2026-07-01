#include <vector>
//
// Created by Geek.Kwok on 7/1/26.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        // 初始化
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2;
        // 顺序
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        // 答案
        return dp[n];
    }
};