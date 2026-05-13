//
// Created by Emme.Kwok on 2026/5/13.
//
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n + 1, 0), dp2(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        dp2[2] = nums[1];
        for (int i = 3; i <= n; i++)
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        return max(dp[n - 1], dp2[n]);
    }
};