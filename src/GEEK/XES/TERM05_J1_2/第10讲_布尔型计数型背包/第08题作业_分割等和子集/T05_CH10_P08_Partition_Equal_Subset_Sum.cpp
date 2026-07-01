//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n;
    cin >> n;
    int s = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
    if (s % 2 == 1) cout << "No" << endl, exit(0);
    // 题型：恰好型01背包问题
    // 状态：dp[j]代表前i个数字和恰好为j的方案数
    // 初始化
    s /= 2;
    vector<long long> dp(s + 1, INF);  // 初始状态不可达
    dp[0] = 1;
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = s; j >= a[i]; j--) {
            if (dp[j] == INF) dp[j] = dp[j - a[i]];  // 首次初始化
            else if (dp[j] != INF && dp[j - a[i]] != INF) dp[j] += dp[j - a[i]];
        }
    // 答案
    if (dp[s] != INF) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}