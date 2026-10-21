//
// Created by Emme.Kwok on 2026/10/8.
//
#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == k) dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            long long ans = a[i];
            for (int s = i + 1; s <= j; s++) ans ^= a[s];
            if (ans == k) dp[i][j] = 1;
            for (int s = i; s < j; s++)
                dp[i][j] = max(dp[i][j], dp[i][s] + dp[s + 1][j]);
        }
    cout << dp[1][n] << "\n";
    return 0;
}