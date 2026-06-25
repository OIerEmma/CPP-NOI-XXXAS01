//
// Created by Emme.Kwok on 2026/6/25.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // IO优化：加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 读入数据
    int n;
    cin >> n;
    // 生成物品
    vector<int> a;
    for (int i = 1; i * i <= n; i++) a.push_back(i * i);  // 0-based
    // 核心算法
    const int N = (int)a.size(), INF = 1e9;
    // 定义状态：dp[i]代表完全平方数的总和恰好为i时最小个数
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = a[i - 1]; j <= n; j++)
            if (dp[j - a[i - 1]] != INF) dp[j] = min(dp[j - a[i - 1]] + 1, dp[j]);
    // 输出结果
    cout << dp[n] << endl;
    return 0;
}