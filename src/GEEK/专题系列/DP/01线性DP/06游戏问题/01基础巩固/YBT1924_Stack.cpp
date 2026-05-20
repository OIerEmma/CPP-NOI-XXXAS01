//
// Created by Geek.Kwok on 2026/5/19.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 状态定义: dp[i][j] 还剩 i 个元素待入栈、当前栈中有j个元素的方案数
    // 即 dp[i][j] = 从初始状态(n,0)出发，到达状态(i,j)的不同操作序列总数
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