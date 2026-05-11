//
// Created by Emme.Kwok on 2026/5/5.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int change(int k, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (i < coins[j]) continue;
                dp[i] += dp[i - coins[j]];
            }
        }
        return dp[k];
    }
};