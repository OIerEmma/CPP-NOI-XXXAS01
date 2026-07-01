//
// Created by Geek.Kwok on 5/11/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 输入
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) cin >> a[i][j];
    // 初始化
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++) dp[n][j] = a[n][j];  // 最下面一层为数字本身
    // 顺序
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
    // 答案
    cout << dp[1][1] << endl;
    return 0;
}