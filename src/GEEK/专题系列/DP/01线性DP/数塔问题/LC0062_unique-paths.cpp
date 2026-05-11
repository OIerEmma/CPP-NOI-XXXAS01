//
// Created by Geek.Kwok on 5/11/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 初始化
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        // 计算顺序
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 返回结果
        return dp[m - 1][n - 1];
    }
};