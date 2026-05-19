//
// Created by Geek.Kwok on 2026/5/19.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 状态定义 dp[i] 从1构建到i的方案数
    // 状态转移方程 dp[i] = Sum { dp[j], 1 <= j < 2/i }
    // 初始化
    vector<int> dp(n + 1, 1);
    // 计算顺序
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i/2; j++)
            dp[i] += dp[j];
    // 返回结果
    cout << dp[n] << endl;
    return 0;
}