//
// Created by Geek.Kwok on 2026/10/8.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_xor_sum.in", "r", stdin);
    // freopen("g_xor_sum.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n; long long k;
    cin >> n >> k;
    vector<long long> a(n + 1), dp(n + 1, 0);
    cin >> a[1]; dp[1] = a[1] == k ? 1 : 0;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i - 1];
        long long ans = a[i];
        if (ans == k) dp[i] = max(dp[i], dp[i - 1] + 1);
        for (int j = i - 1; j >= 1; j--) {
            ans ^= a[j];
            if (ans == k) dp[i] = max(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}