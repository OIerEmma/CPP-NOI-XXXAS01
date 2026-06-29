//
// Created by Geek.Kwok on 5/19/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 完全背包问题求方案数
        // 状态定义：DP[j] 前i个数的总和恰好为j的总方案数
        // 初始化
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        // 计算顺序
        for (int i = 1; i <= target; i++)
            for (int num: nums)
                if (i >= num)
                    dp[i] += dp[i - num];
        // 返回结果
        return dp[target];
    }

    int combinationSum4_2(vector<int>& nums, int target) {
        int n = nums.size();
        // 完全背包问题求方案数
        // 状态定义：DP[i][j] 前i个数的总和恰好为j的总方案数
        // 初始化
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(target + 1, 0));
        dp[0][0] = 1;
        // 计算顺序
        // for (int i = 1; i <= target; i++)
        //     for (int num: nums)
        //         if (i >= num)
        //             DP[i] += DP[i - num];
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= target; j++) {
                int maxK = j / nums[i - 1];
                for (int k = 0; k <= maxK; k++)
                    dp[i][j] += dp[i - 1][j - k * nums[i-1]];
            }
        // 返回结果
        return dp[n][target];
    }
};

int main() {
    return 0;
}