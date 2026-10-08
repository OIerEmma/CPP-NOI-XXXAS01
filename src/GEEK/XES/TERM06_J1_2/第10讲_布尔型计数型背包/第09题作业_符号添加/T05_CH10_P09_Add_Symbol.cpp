//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

const int OFFSET = 10005, MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 题型：
    // 状态：dp[i][j+OFFSET]代表前i个数经过符号添加后运算结果为j的方案数
    // 初始化
    vector<vector<int>> dp(n + 1, vector<int>(2 * OFFSET, 0));
    dp[0][OFFSET] = 1;
    // 顺序
    for (int i = 0; i < n; i++) {
        for (int j = -10000; j <= 10000; j++) {  // 正序，二维01背包（由于加减操作会导致依赖方向不确定）
            if (j + a[i] <= 10000)  // +
                dp[i + 1][j + OFFSET] = (dp[i + 1][j + OFFSET] + dp[i][j + a[i] + OFFSET]) % MOD;
            if (j - a[i] >= -10000)  // -
                dp[i + 1][j + OFFSET] = (dp[i + 1][j + OFFSET] + dp[i][j - a[i] + OFFSET]) % MOD;
        }
    }
    // 答案
    cout << dp[n][m + OFFSET] << endl;
    return 0;
}