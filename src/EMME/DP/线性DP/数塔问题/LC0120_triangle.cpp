//
// Created by Emme.Kwok on 2026/5/11.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        for (int i = 0; i < n; i++) dp[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        return dp[0][0];
    }
};