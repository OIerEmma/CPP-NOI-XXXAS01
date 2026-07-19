//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    // 状态：dp[i][j]代表左端点为i，右端点为j的区间中，合并可得到的最大得分
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)), dp2(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
                dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    cout << dp[1][n] << endl << dp2[1][n] << endl;
    return 0;
}