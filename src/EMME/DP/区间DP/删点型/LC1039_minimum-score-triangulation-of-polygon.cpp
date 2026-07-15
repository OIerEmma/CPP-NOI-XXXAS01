//
// Created by Emme.Kwok on 2026/7/15.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = (int)values.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int len = 3; len <= n; len++)
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = 1e9;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
            }
        return dp[0][n - 1];
    }
};