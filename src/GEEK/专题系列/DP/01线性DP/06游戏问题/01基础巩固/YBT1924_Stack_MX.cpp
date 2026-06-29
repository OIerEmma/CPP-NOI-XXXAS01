//
// Created by Geek.Kwok on 5/20/26.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int n;
    cin >> n;
    // 状态定义：DP[i][j] 表示还有i个元素待入栈、栈中有j个元素的总方案数
    // 初始化
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[n][0] = 1;
    // 计算顺序
    for (int i = n; i >= 0; i--)
        for (int j = n; j >= 0; j--) {
            if (i + j > n) continue;
            if (i == n && j == 0) continue;
            if (j >= 1) dp[i][j] += dp[i + 1][j - 1];
            if (i + j < n) dp[i][j] += dp[i][j + 1];
        }
    cout << dp[0][0] << endl;
    return 0;
}