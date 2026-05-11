//
// Created by Geek.Kwok on 5/11/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int INF = 1e9;
        // 初始化
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int j = 0; j < n; ++j) dp[n-1][j] = triangle[n-1][j];
        // 计算顺序
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        // 返回结果
        return dp[0][0];
    }
};