//
// Created by Geek.Kwok on 2026/5/19.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // 状态定义 DP[i] 点菜恰好i元的方案总数
    // 初始化
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    // 计算顺序
    for (int i = 0; i < n; i++)
        for (int j = m; j >= arr[i]; j--)
            dp[j] += dp[j - arr[i]];
    // 返回结果
    cout << dp[m] << endl;
    return 0;
}