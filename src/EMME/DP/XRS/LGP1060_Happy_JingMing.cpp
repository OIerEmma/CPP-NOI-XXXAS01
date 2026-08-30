//
// Created by Emme.Kwok on 2026/8/27.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    vector<int> v(m + 1), p(m + 1);
    for (int i = 0; i < m; i++) cin >> v[i] >> p[i];
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (v[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + v[i - 1] * p[i - 1]);
        }
    cout << dp[m][n] << endl;
    return 0;
}