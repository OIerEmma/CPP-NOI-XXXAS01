//
// Created by Emme.Kwok on 2026/7/4.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> c[i];
    // 状态：dp[j]代表容量不超过j时的最大价值
    // 初始化
    vector<int> dp(m + 1, 0);
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
    // 答案
    cout << "max=" << dp[m] << endl;
    return 0;
}