//
// Created by Geek.Kwok on 5/14/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1, count = 0;

        // DP[i] 以i为结尾的最长上升子序列长度
        // cnt[i] 以i为结尾的最长上升子序列出现的次数
        vector<int> dp(n, 1), cnt(n, 1);
        // 计算顺序
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        // 情况1：发现更长的子序列，则重置为更长序列的次数
                        dp[i] = max(dp[i], dp[j] + 1);
                        cnt[i] = cnt[j]; // 重置计数
                    } else if (dp[j] + 1 == dp[i]) {
                        // 情况2：发现同样长的子序列，则次数累加
                        cnt[i] += cnt[j];
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        // 求总次数
        for (int i = 0; i < n; i++) if (ans == dp[i]) count += cnt[i];
        // 返回结果
        return count;
    }
};

// 1 3 5 4 7
// DP[]
// 1 2 3 3 4
// cnt[]
// 1 1 2

// 需要两个 DP 数组：len[i] 记录以 i 结尾的 LIS 长度，cnt[i] 记录对应的方案数。转移时若 len[j] + 1 > len[i] 则更新长度并重置计数；若相等则累加计数。最终将所有 len[i] == maxLen 的 cnt[i] 相加。