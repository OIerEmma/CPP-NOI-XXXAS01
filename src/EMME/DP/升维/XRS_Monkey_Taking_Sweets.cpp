//
// Created by Emme.Kwok on 2026/7/21.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        dp[1][1] = a[1];
        for (int i = 2; i <= n; i++) dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]), dp[i][1] = dp[i - 1][0] + a[i];
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}