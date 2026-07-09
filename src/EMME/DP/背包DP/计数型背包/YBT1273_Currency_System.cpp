//
// Created by Emme.Kwok on 2026/7/8.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = (int)nums.size();
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= target; j++)
            for (int i = 0; i < n; i++)
                if (j >= nums[i]) dp[j] += dp[j - nums[i]];
        return dp[target];
    }
};