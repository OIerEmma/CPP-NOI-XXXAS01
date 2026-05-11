//
// Created by Emme.Kwok on 2026/5/4.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int k) {
        int memo[k + 1], n = coins.size();
        // 第5步：确定初始条件
        memo[0] = 0;
        for (int i = 1; i <= k; i++) memo[i] = k + 1;
        // 第6步：确定计算顺序
        for (int i = 1; i <= k; i++) {
            for (int coin = 1; coin <= n; coin++) {
                if (coins[coin] > i) continue;
                cout << i - coins[coin] << endl;
                memo[i] = min(memo[i - coins[coin]] + 1, memo[i]);
            }
        }
        // 第7步：确定返回结果
        return memo[k] == k + 1 ? -1 : memo[k];
    }
};