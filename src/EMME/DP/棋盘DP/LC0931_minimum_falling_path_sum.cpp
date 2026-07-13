//
// Created by Emme.Kwok on 2026/7/11.
//
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, MAX));
        for (int i = 0; i < n; i++) dp[n - 1][i] = matrix[n - 1][i];
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i + 1][max(j - 1, 0)], min(dp[i + 1][j], dp[i + 1][min(j + 1, n)])) + matrix[i][j];
        int ans = MAX;
        for (int i = 0; i < n; i++) ans = min(ans, dp[0][i]);
        return ans;
    }
};