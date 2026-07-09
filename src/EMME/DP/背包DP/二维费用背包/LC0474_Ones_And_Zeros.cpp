//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = (int)strs.size();
        vector<int> o(l, 0), z(l, 0);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') z[i]++;
                else o[i]++;
            }
        // dp[i][j]代表选择子集0不超过i个，1不超过j个的最大子集长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < l; i++)
            for (int x = m; x >= z[i]; x--)
                for (int y = n; y >= o[i]; y--)
                    dp[x][y] = max(dp[x - z[i]][y - o[i]] + 1, dp[x][y]);
        return dp[m][n];
    }
};