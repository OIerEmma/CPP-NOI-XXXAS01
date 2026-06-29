//
// Created by Emme.Kwok on 2026/6/19.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = n; j >= 0; j--)
            if (i + j <= n) {
                if (j + 1 <= n) dp[i][j] += dp[i][j + 1];
                if (j - 1 >= 0) dp[i][j] += dp[i + 1][j - 1];
            }
    cout << dp[0][0] << endl;
    return 0;
}
/*
1.划分阶段：这个问题可以划分成哪些阶段？每个阶段在做什么决定？
    针对一个数字，可以选择入栈或出栈
2.定义状态：DP[i] 或 DP[i][j] 代表什么？存的是最大值，最小值还是方案数
    DP[i][j] 还剩i个元素待入栈、当前栈中有j个元素的方案数
3.分析决策
    · 有哪些选择？DP[i][j] -> DP[i - 1][j + 1]/DP[i][j - 1]
    · 从哪转移？DP[i + 1][j - 1]/DP[i][j + 1] -> DP[i][j]
    · dp值怎么变？DP[i][j] += DP[i][j + 1] + DP[i + 1][j - 1]
4.状态转移方程
    DP[i][j] += DP[i][j + 1] + DP[i + 1][j - 1]
5.确定初始条件
    DP[n][0] = 1;
6.确定计算顺序
    外层从大到小，内层从大到小
7.确定返回结果
    return DP[0][0];
*/