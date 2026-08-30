//
// Created by Emme.Kwok on 2026/8/28.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int sum, sum2 = 0, last, ans;
        sum = last = ans = nums[0];
        for (int i = 1; i < n; i++) {
            last = max(last + nums[i], nums[i]);
            ans = max(ans, last);
            sum += nums[i];
            dp[i] = max(dp[i - 1], sum);
        }
        for (int i = n - 1; i > 0; i--) {
            sum2 += nums[i];
            ans = max(ans, sum2 + dp[i - 1]);
        }
        return ans;
    }
};