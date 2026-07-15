//
// Created by Emme.Kwok on 2026/7/15.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            long long best = 0;
            for (int k = i; k <= j; k++) {
                long long left = k - 1 >= i ? dp[i][k - 1] : 0;
                long long right = k + 1 <= j ? dp[k + 1][j] : 0;
                best = max(best, left + right);
            }
            dp[i][j] = best + a[i - 1] + a[j + 1];
        }
    cout << dp[1][n] << endl;
    return 0;
}