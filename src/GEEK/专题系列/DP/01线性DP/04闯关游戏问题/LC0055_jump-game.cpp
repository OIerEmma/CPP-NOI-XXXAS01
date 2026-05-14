//
// Created by Geek.Kwok on 5/13/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp[i] 从i为起点，是否可以跳到终点 true是/false否
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= nums[i]; j++)
                if (i + j < n)
                    dp[i] = dp[i] || dp[i + j];
        return dp[0];
    }
};