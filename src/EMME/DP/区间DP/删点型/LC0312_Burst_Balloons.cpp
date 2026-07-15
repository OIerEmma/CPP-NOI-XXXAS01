//
// Created by Emme.Kwok on 2026/7/15.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> num(n + 2, 1);
        vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
        for (int i = 1; i <= n; i++) num[i] = nums[i - 1];
        for (int len = 1; len <= n; len++)
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    long long left = k - 1 >= i ? dp[i][k - 1] : 0;
                    long long right = k + 1 <= j ? dp[k + 1][j] : 0;
                    dp[i][j] = max(dp[i][j], left + right + num[i - 1] * num[k] * num[j + 1]);
                }
            }
        return dp[1][n];
    }
};