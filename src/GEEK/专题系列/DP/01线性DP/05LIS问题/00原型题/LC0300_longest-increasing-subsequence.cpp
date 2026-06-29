//
// Created by Geek.Kwok on 5/14/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // O(n2)标准DP
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        // DP[i] 以i为结尾的最长上升子序列的长度
        vector<int> dp(n, 1); // 自身可以成为一个子序列
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    // O(nlogn)优化：贪心+二分
    int lengthOfLIS2(vector<int>& nums) {
        // tails[i] 长度为i+1的递增子序列，它的最后一个数最小值可以是多少
        vector<int> tails;
        for (int x: nums) {
            // 在tails数组里二分查找第一个大于等于x的位置
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x); // x比所有末尾都大则延长队伍
            else *it = x; // 否则替换掉那个位置，让末尾更小（贪心：同样长度的递增序列，末尾越小，队伍长度才可能更大）
        }
        return tails.size();
    }
};