//
// Created by Emme.Kwok on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}

/*
1.划分阶段
2.定义状态：dp[i]代表总和为i时的完全平方数最少数量
3.决策分析：
    1.有哪些选择？加上平方数但不超过n
    2.从哪里转移？往前找，减去平方数但不小于0
    3.dp值怎么变？dp[i] = min(dp[i - j * j])
4.状态转移方程：
    dp[i] = min(dp[i - j * j] + 1), 1 <= j, j * j <= i
5.确定初始条件：dp[0] = 0, dp[i] = i, 1 <= i <= n
6.确定计算顺序：从小到大
7.确定返回结果：dp[n]
*/