//
// Created by Emme.Kwok on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // IO优化：加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 读入数据
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 核心算法
    // 定义状态：dp[i]代表人数恰好为i时讨论积极度的最大值
    // 初始化
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) dp[i] = a[i];
    // 计算顺序
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            dp[j] = max(dp[j - i] + a[i], dp[j]);
    // 输出结果
    cout << dp[n] << endl;
    return 0;
}

/**
背包问题  此题问题
---： ---
物品i：人数为i的小组i
物品i的重量w[i]：小组i的人数i
物品i的价值v[i]：小组i的讨论积极度a[i]
背包总容量W：班级总人数n
恰好型背包问题：容量恰好为W时的最大价值
映射这道题问题：班级总人数恰好为n时的最大积极度
 */