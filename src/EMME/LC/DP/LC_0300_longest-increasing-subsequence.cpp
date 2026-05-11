//
// Created by Emme.Kwok on 2026/5/5.
//
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size(), ans = 1;
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[j - 1] < nums[i - 1])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int lengthOfLIS2(vector<int>& nums) {
        int n = (int)nums.size(), ans = 1;
        vector<int> dp(n + 1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};