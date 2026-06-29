//
// Created by Geek.Kwok on 2026/5/19.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 状态定义: DP[i][j] 当前栈中有j个元素、还剩i个元素待入栈的方案数
    // 初始化
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[n][0] = 1;
    // 计算顺序 拉取式递推：i 递减，j 递减
    for (int i = n; i >= 0; i--)
        for (int j = n; j >= 0; j--) {
            if (i + j > n) continue; // 不可达状态
            if (i == n && j == 0) continue; // 已初始化状态

            if (j >= 1) dp[i][j] += dp[i + 1][j - 1]; // 来自入栈：上一步状态为 (i+1, j-1)，入栈后到达 (i, j)
            if (i + j < n) dp[i][j] += dp[i][j + 1]; // 来自出栈：上一步状态为 (i, j+1)，出栈后到达 (i, j)
        }
    cout << dp[0][0] << endl;
    return 0;
}