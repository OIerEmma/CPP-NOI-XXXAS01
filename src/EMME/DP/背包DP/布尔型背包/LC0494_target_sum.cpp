//
// Created by Emme.Kwok on 2026/7/7.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, n = (int)nums.size();
        for (int i = 0; i < n; i++) sum += nums[i];
        int p = sum + target;
        if (p % 2 || p < 0) return 0;
        p /= 2;
        vector<int> dp(p + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = p; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
        return dp[p];
    }
};