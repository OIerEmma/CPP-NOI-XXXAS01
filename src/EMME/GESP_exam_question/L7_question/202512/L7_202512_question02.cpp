//
// Created by Emme.Kwok on 2026/9/11.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(c.begin(), c.end());
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    long long ans = 0;
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= n; j++)
            for (int k = i; k <= n; k++) {
                int diff = (i > 1) ? c[n - j + 1] - c[j] : 0;
                dp[j][k] = max(dp[j][k], dp[j - 1][k - i] + a[i] + diff);
                if (k == n) ans = max(ans, dp[j][k]);
            }
    cout << ans << endl;
    return 0;
}