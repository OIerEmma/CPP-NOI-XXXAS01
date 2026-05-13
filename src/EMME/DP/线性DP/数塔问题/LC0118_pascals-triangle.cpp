//
// Created by Emme.Kwok on 2026/5/13.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        for (int i = 0; i < numRows; i++) dp[i] = vector<int>(i + 1);
        for (int i = 0; i < numRows; i++) dp[i][0] = 1, dp[i][i] = 1;
        for (int i = 2; i < numRows; i++)
            for (int j = 1; j < i; j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        return dp;
    }
};