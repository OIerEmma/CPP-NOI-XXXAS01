//
// Created by Emme.Kwok on 2026/8/3.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = (int)strs.size();
        vector<int> o(len, 0), z(len, 0);
        for (int i = 0; i < len; i++)
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '1') o[i]++;
                else z[i]++;
            }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < len; i++)
            for (int x = m; x >= z[i]; x--)
                for (int y = n; y >= o[i]; y--)
                    dp[x][y] = max(dp[x - z[i]][y - o[i]] + 1, dp[x][y]);
        return dp[m][n];
    }
};