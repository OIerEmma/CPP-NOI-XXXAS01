//
// Created by Geek.Kwok on 5/14/26.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        // 用哈希表统计各个数字的频率
        unordered_map<int, int> freq;
        for (auto x : nums) freq[x]++;
        // 遍历哈希表寻找潜在搭档
        int ans = 0;
        for (auto x : freq)
            if (freq.count(x.first + 1)) {
                int currLen = x.second + freq[x.first + 1];
                ans = max(ans, currLen);
            }
        // 返回结果
        return ans;
    }
};

/**
T20. 最长和谐子序列
- 来源：LeetCode 594
- 难度：简单 ⭐
- 核心提示：子序列中最大最小值之差恰好为 1。可用哈希表统计频率后枚举，是 LIS 思想的简化应用。虽然是简单题，但展示了 DP 不局限于严格递推——有时结合哈希表能更高效。
- 链接：https://leetcode.cn/problems/longest-harmonious-subsequence/
 */