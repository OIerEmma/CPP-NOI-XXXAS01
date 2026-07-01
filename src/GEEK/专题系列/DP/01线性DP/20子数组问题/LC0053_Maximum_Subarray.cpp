//
// Created by Geek.Kwok on 7/1/26.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // 初始化
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) dp[i] = nums[i - 1];
        // 顺序
        int ans = dp[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            ans = max(ans, dp[i]);
        }
        // 答案
        return ans;
    }
};