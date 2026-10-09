//
// Created by Emme.Kwok on 2026/10/8.
//
#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> dp(n + 1, 0);
    dp[1] = a[1] == k ? 1 : 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        long long ans = a[i];
        if (ans == k) dp[i] = dp[i - 1] + 1;
        for (int l = i - 1; l >= 1; l--) {
            ans ^= a[l];
            if (ans == k) dp[i] = max(dp[i], dp[l - 1] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}