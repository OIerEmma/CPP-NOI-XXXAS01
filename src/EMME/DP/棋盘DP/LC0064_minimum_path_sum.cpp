//
// Created by Emme.Kwok on 2026/7/11.
//
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, MAX));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        return dp[m - 1][n - 1];
    }
};