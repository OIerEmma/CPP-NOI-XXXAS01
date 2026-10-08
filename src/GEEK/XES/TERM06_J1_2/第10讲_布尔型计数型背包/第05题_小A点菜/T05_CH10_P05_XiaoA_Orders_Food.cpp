//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 状态：dp[i]代表点菜花费恰好为i的方案数
    // 初始化
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = m; j >= a[i]; j--)
            dp[j] += dp[j - a[i]];
    // 答案
    cout << dp[m] << endl;
    return 0;
}