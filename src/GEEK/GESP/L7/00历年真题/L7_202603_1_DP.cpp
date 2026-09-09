//
// Created by Geek.Kwok on 2026/9/9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;                                 // 第 5 步：空乘积为 1
        for (int i = 1; i <= n; i++) dp[i] = i;    // 允许不拆
        for (int i = 2; i <= n; i++)               // 第 1 步：段长当物品
            for (int j = i; j <= n; j++)           // 第 6 步：完全背包，正序
                dp[j] = max(dp[j], dp[j - i] * i); // 第 3、4 步（逆向/拉）
        cout << dp[n] % 1000000000LL << endl;      // 第 7 步；n<=50 时模不模都一样
    }
    return 0;
}