//
// Created by Geek.Kwok on 2026/5/11.
//
#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) { return {{1}};}
        vector<vector<int>> dp(numRows);
        dp[0] = {1}, dp[1] = {1, 1};
        for (int i = 2; i < numRows; i++) {
            dp[i] = vector<int>(i + 1, 0);
            dp[i][0] = dp[i][i] = 1;
            for (int j = 1; j < i; j++)
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
        return dp;
    }
};