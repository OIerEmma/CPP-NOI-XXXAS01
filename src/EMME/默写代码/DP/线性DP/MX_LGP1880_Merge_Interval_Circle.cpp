//
// Created by Geek.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(2 * n + 1), s(2 * n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) a[i + n] = a[i], s[i + n] = s[i + n - 1] + a[i + n];
    vector<vector<long long>> dp(2 * n + 1, vector<long long>(2 * n + 1, 0));
    vector<vector<long long>> dp2(2 * n + 1, vector<long long>(2 * n + 1, 0));
    for (int len = 2; len <= 2 * n; len++)
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            dp2[i][j] = 1e9;
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
                dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    long long ans = 0, ans2 = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][i + n]);
        ans2 = min(ans2, dp[i][i + n]);
    }
    cout << ans << endl << ans2 << endl;
    return 0;
}