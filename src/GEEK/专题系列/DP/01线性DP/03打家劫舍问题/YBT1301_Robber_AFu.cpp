//
// Created by Geek.Kwok on 2026/5/12.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    std::ios::sync_with_stdio(false);
    // std::ios::tie(nullptr);
    while (t--) {
        cin >> n;
        vector<int> a(n), dp(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        dp[0] = 0, dp[1] = a[0];
        for (int i = 2; i <= n; i++) dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1]);
        cout << dp[n] << endl;
    }
}