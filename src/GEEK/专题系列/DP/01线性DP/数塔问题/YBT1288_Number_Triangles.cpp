//
// Created by Geek.Kwok on 5/11/26.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int n;
    cin >> n;
    vector<vector<int>> triangles(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangles[i][j];
        }
    }
    // 初始化
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++) dp[n][j] = triangles[n][j];
    // 状态转移
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + triangles[i][j];
        }
    }
    // 返回结果
    cout << dp[1][1] << endl;
    return 0;
}