//
// Created by Geek.Kwok on 5/12/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        // DP[i] 街道一侧前 n 个地块可以放的总方案数
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        return (int) dp[n] * dp[n] % MOD;
    }
};