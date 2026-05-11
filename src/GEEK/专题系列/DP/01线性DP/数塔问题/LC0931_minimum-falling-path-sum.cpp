//
// Created by Geek.Kwok on 5/11/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // 初始化
        const int INF = 1e9;
        int n = matrix.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, INF));
        for (int j = 0; j < n; j++) dp[n][j+1] = matrix[n-1][j];
        // 计算顺序
        for (int i = n-2; i >= 0; i--) {
          for (int j = n-1; j >= 0; j--) {
            dp[i+1][j+1] = min(min(dp[i+1+1][j-1+1], dp[i+1+1][j+1]), dp[i+1+1][j+1+1]) + matrix[i][j];
          }
        }
        // 返回结果
        int ans = INF;
        for (int j = 0; j < n; j++) {
          ans = min(ans, dp[0+1][j+1]);
        }
        return ans;
    }
};