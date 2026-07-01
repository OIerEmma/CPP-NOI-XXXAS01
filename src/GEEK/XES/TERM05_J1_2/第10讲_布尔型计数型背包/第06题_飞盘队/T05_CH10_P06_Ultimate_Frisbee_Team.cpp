//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e8;

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> cow(n);
    for (int i = 0; i < n; i++) cin >> cow[i], cow[i] %= f;
    // 状态：dp[i][j]代表前i头组成能力j小队的总方案数
    // 初始化
    vector<vector<int>> dp(n + 1, vector<int>(f + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < f; j++)  // 正序，二维01背包（由于求模操作会导致依赖方向不确定）
            dp[i + 1][j] = (dp[i][j] + dp[i][(j - cow[i] + f) % f]) % MOD;
    cout << dp[n][0] - 1 << endl;  // 队员数不小于0
    return 0;
}