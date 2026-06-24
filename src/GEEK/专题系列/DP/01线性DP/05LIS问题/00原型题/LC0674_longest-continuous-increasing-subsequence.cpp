//
// Created by Geek.Kwok on 5/14/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};