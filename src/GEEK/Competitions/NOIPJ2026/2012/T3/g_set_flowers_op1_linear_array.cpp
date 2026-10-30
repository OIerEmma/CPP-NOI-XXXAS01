//
// Created by Geek.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp(m + 1, 0); // 一维数组逆序
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--) // 逆序写法
            for (int t = 1; t <= a[i] && t <= j; t++) // 第i种花摆t盆
                dp[j] = (dp[j] + dp[j - t]) % MOD;
    cout << dp[m] << endl;
    return 0;
}