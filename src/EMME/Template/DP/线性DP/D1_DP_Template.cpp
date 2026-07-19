//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 定义状态：达到第i个房间的最大值
    vector<int> dp(n + 1, 0);
    // 初始化
    dp[0] = 0, dp[1] = a[0];
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1]);
    cout << dp[n] << endl;
    return 0;
}