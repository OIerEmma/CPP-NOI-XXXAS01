//
// Created by Emme.Kwok on 2026/9/11.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(m + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i]; j--)
            for (int k = x; k >= b[i]; k--)
                dp[j][k] = max(dp[j][k], dp[j - a[i]][k - b[i]] + c[i]);
    cout << dp[m][x] << endl;
    return 0;
}