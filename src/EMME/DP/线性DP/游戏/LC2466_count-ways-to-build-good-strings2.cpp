//
// Created by Emme.Kwok on 2026/6/1.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 2);
        const int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            // 状态转移方程
            if (i - zero >= 0) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i - one >= 0) dp[i] = (dp[i] + dp[i - one]) % mod;
        }
        int ans = 0;
        for (int i = low; i <= high; i++) ans = (ans + dp[i]) % mod;
        return ans;
    }
};