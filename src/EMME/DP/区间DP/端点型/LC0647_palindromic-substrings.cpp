//
// Created by Emme.Kwok on 2026/7/17.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string &s) {
        int n = (int)s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; i++) dp[i][i] = true;
        for (int len = 2; len <= n; len++)
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                if (s[i - 1] == s[j - 1] && (i + 1 == j || dp[i + 1][j - 1])) dp[i][j] = true;
            }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) ans += dp[i][j];
        return ans;
    }
};