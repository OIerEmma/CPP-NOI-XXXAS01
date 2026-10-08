//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, begin, mx;
    cin >> n >> begin >> mx;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    // 状态：dp[i][j]代表前i首歌最后调至j音量是否可行
    // 初始化
    vector<vector<bool>> dp(n + 1, vector<bool>(mx + 1, false));
    dp[0][begin] = true;
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= mx; j++) {  // 正序，使用二维01背包，因为音量可调高调低，故不确定从哪个方向转移而来
            if (j - c[i] >= 0)
                dp[i + 1][j] = dp[i + 1][j] || dp[i][j - c[i]];
            if (j + c[i] <= mx)
                dp[i + 1][j] = dp[i + 1][j] || dp[i][j + c[i]];
        }
    // 答案
    for (int j = mx; j >= 0; j--) if (dp[n][j]) cout << j << endl, exit(0);
    cout << -1 << endl;
    return 0;
}