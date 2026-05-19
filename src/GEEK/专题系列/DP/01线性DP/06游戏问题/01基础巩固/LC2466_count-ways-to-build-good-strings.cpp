//
// Created by Geek.Kwok on 2026/5/19.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // 状态定义 dp[i] 长度为 i 字符串的方案数
        // 状态转移方程 dp[i] = dp[i - one] + dp[i - zero]
        // 初始化
        const int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        // 计算顺序
        for (int i = 1; i < high + 1; i++) {
            if (i - zero >= 0) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i - one >= 0) dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
        // 返回结果
        int ans = 0;
        for (int i = low; i <= high; i++) ans = (ans + dp[i]) % MOD;
        return ans;
    }
};

int main() {
    return 0;
}