//
// Created by Emme.Kwok on 2026/7/7.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = (int)stones.size(), sum = 0;
        for (int i = 0; i < n; i++) sum += stones[i];
        int tot = sum / 2;
        vector<bool> dp(tot + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++)
            for (int j = tot; j >= stones[i]; j--)
                dp[j] = dp[j] || dp[j - stones[i]];
        int ans = tot;
        for (int i = tot; i >= 0; i--)
            if (dp[i]) { ans = i; break; }
        return sum - ans - ans;
    }
};