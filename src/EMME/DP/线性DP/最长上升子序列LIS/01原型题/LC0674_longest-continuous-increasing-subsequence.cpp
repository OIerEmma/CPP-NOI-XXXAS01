//
// Created by Emme.Kwok on 2026/5/21.
//
#include<vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = (int)nums.size(), ans = 1;
        vector<int> dp(n + 1, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                dp[i] = max(dp[i], dp[i - 1] + 1);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};