//
// Created by Emme.Kwok on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i - j] + a[j], dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}
/*
1.划分阶段：针对一个同学，划分到前面的队伍中的一个，或成为一个新的队伍
2.定义状态：dp[i]表示人数为i时积极度的最大值
3.分析决策：
    1.有哪些选择？决策允许集合：假设当前在i，dp[i + j] = dp[j] + a[j]
    2.从哪里转移？状态转移过程：假设当前在i，向前推，dp[i] = dp[i - j] + a[j]
    3.dp值怎么变？状态结果计算：dp[i] = min(dp[i - j] + a[j])
4.写出状态转移方程：dp[i] = min(dp[i - j] + a[j]), 1 <= j <= i
5.确定初始条件：dp[0] = 0, dp[1] = a[1]
6.确定计算顺序：从小到大
7.确定返回结果：dp[n]
*/