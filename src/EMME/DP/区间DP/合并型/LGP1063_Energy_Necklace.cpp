//
// Created by Emme.Kwok on 2026/7/13.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    vector<long long> a(2 * n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i], a[n + i] = a[i];
    a[2 * n + 1] = a[1];
    vector<vector<long long>> dp(2 * n + 1, vector<long long>(2 * n + 1, 0));
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
        }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i][n + i - 1]);
    cout << ans << endl;
    return 0;
}