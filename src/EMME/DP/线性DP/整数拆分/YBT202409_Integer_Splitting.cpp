//
// Created by Emme.Kwok on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++)
        if ((int)sqrt(i) * (int)sqrt(i) == i) dp[i] = 1;
        else for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
    // for (int i = 1; i <= n; i++) cout << dp[i] << endl;
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
5.确定初始条件：dp[0] = 1, dp[1] = 1
6.确定计算顺序：从小到大
7.确定返回结果：dp[n]
*/