//
// Created by Emme.Kwok on 2026/7/11.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = (int)triangle.size();
        vector<vector<int>> dp(r + 1, vector<int>(r + 1, 0));
        for (int i = 0; i < r; i++) dp[r - 1][i] = triangle[r - 1][i];
        for (int i = r - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        return dp[0][0];
    }
};