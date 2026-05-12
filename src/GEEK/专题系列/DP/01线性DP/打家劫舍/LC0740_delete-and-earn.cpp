//
// Created by Geek.Kwok on 5/12/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 转换数组
        int n = nums.size(), maxv = nums[0];
        for (int i = 1; i < n; i++) if (nums[i] > maxv) maxv = nums[i];
        vector<int> ns(maxv + 1, 0);
        for (int i = 0; i < n; i++) ns[nums[i]]++;
        for (int i = 0; i <= maxv; i++) ns[i] = ns[i] * i;
        // 初始化
        vector<int> dp(maxv + 2, 0);
        dp[1] = ns[0];
        // 计算顺序
        for (int i = 2; i <= maxv + 1; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + ns[i - 1]);
        // 返回结果
        return dp[maxv + 1];
    }
};