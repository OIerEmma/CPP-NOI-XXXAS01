//
// Created by Geek.Kwok on 2026/5/14.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // 初始化
        int n = arr.size(), ans = 1;
        unordered_map<int, int> dp;
        dp[arr[0]] = 1;
        // 计算顺序：使用哈希表来优化效率使整体O(n)
        for (int i = 1; i < n; i++) {
            int x = arr[i]; // 当前的数
            if (dp[x - difference]) dp[x] = dp[x - difference] + 1; // 存在dp[x-d]则累加
            else dp[x] = 1; // 否则初始值为1
            ans = max(ans, dp[x]);
        }
        // 返回结果
        return ans;
    }
};