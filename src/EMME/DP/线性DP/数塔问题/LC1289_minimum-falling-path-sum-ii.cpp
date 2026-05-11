//
// Created by Emme.Kwok on 2026/5/11.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        for (int i = 0; i < n; i++) dp[n - 1][i] = matrix[n - 1][i];
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++)
                    if (j != k) dp[i][j] = min(dp[i + 1][k], dp[i][j]);
                dp[i][j] += matrix[i][j];
            }
        int ans = 1e9;
        for (int i = 0; i < n; i++) ans = min(ans, dp[0][i]);
        return ans;
    }
};