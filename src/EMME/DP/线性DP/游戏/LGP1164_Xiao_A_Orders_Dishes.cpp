//
// Created by Emme.Kwok on 2026/6/18.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = a[i]; j <= m; j++)
            dp[i + 1][j] = dp[i][j] + dp[i][j - a[i]];
    cout << dp[n][m] << endl;
    return 0;
}