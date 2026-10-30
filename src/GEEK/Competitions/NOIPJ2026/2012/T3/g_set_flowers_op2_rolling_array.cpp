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
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> ndp(m + 1, 0); // 滚动数组
        for (int j = 0; j <= m; j++) // 正序写法
            for (int t = 0; t <= a[i] && t <= j; t++) // 第i种花摆t盆
                ndp[j] = (ndp[j] + dp[j - t]) % MOD;
        dp = ndp;
    }
    cout << dp[m] << endl;
    return 0;
}