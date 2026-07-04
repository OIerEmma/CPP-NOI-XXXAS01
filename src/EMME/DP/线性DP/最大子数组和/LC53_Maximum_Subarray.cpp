//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) dp[i] = nums[i - 1];
        for (int i = 1; i <= n; i++)
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
        return *max_element(dp.begin() + 1, dp.end());
    }
};