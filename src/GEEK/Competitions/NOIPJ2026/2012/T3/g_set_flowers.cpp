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
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= m; k++) dp[i][k] = dp[i - 1][k];
        for (int j = 1; j <= a[i]; j++)
            for (int k = j; k <= m; k++)
                dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % MOD;
    }
    cout << dp[n][m] << endl;
    return 0;
}