//
// Created by Emme.Kwok on 2026/5/13.
//
#include<vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxx = 0, n = nums.size();
        for (int i = 0; i < n; i++) maxx = max(maxx, nums[i]);
        vector<int> b(maxx + 1, 0);
        for (int i = 0; i < n; i++) b[nums[i]]++;

        vector<int> dp(maxx + 1, 0);
        dp[1] = b[1];
        for (int i = 2; i <= maxx; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + b[i] * i);
        return dp[maxx];
    }
};