//
// Created by Emme.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int k = m; k >= 0; k--)
            for (int j = 1; j <= a[i] && j <= k; j++)
                dp[k] = (dp[k] + dp[k - j]) % MOD;
    cout << dp[m] << endl;
    return 0;
}