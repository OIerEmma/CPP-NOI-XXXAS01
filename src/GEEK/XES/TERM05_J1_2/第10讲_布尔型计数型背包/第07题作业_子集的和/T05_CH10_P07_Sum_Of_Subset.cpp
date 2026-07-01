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
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(i + 1), s += i + 1;
    if (s % 2 == 1) cout << 0 << endl, exit(0); // 特判：奇数无法划分
    // 题型：恰好型01背包求方案数
    // 状态：dp[i]代表子集和恰好为i的方案数
    // 初始化
    s /= 2;
    vector<long long> dp(s + 1, INF);  // 初始状态不可达
    dp[0] = 1;
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = s; j >= a[i]; j--) {
            if (dp[j] == INF) dp[j] = dp[j - a[i]];  // dp[j]首次初始化
            else if (dp[j] != INF && dp[j - a[i]] != INF) dp[j] += dp[j - a[i]];
        }
    // 答案：n个数中子集和为s(一半)则答案为两倍需除2
    if (dp[s] != INF) cout << dp[s] / 2 << endl;
    else cout << 0 << endl;
    return 0;
}