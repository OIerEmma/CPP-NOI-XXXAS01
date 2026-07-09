//
// Created by Emme.Kwok on 2026/7/4.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size(), ans = 0;
        for (int i = 0; i < n; i++) ans += nums[i];
        if (ans % 2 == 1) return false;
        else ans /= 2;
        vector<bool> dp(ans + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++)
            for (int j = ans; j >= nums[i]; j--)
                dp[j] = dp[j] || dp[j - nums[i]];
        if (dp[ans]) return true;
        return false;
    }
};