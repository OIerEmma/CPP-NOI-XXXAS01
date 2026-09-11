//
// Created by Emme.Kwok on 2026/9/10.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1e9));
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            dp[i][j] = max({dp[i + 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + a[i][j];
    cout << dp[n][m] << endl;
    return 0;
}