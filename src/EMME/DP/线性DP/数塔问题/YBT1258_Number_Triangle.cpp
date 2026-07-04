//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) dp[n - 1][i] = a[n - 1][i];
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
    cout << dp[0][0] << endl;
    return 0;
}