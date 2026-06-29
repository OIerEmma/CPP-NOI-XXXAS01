//
// Created by Emme.Kwok on 2026/6/22.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // 定义状态：DP[i] 代表以 i 为开始 n 为结尾满足条件的最大值 ( 1-based )
    vector<long long> dp(n + 2, 0);
    // 计算顺序
    for (int i = n; i >= 1; i--) {
        dp[i] = dp[i + 1]; // 不选
        dp[i] = max(dp[i], dp[min(i + b[i - 1], n + 1)] + a[i - 1]); // 选
    }
    // 返回结果
    cout << dp[1] << endl;
    return 0;
}
/*
1.划分阶段：这个问题可以划分成哪些阶段？每个阶段在做什么决定？
    针对每一个数字，选或不选
2.定义状态：DP[i] 或 DP[i][j] 代表什么？存储的是最大值，最小值还是方案数？
    DP[i] 代表以 i 为开始 n 为结尾满足条件的最大值
3.分析决策
    · 有哪些选择？决策允许集合：针对一个数字，选或者不选
    · 从哪转移？状态转移过程：不选的话从 i + 1，选的话从 i + b[i]
    · dp值怎么变？状态结果计算：DP[i] = max(DP[i + 1], DP[i + b[i]] + a[i])
4.状态转移方程：
    DP[i] = max(DP[i + 1], DP[i + b[i - 1]] + a[i - 1])
    , i + b[i - 1] <= n, i + 1 <= n
5.确定初始条件：DP[n] = a[n - 1]
6.确定计算顺序：逆序
7.确定返回结果：DP[1]
*/