//
// Created by Emme.Kwok on 2026/9/11.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) dp[i][j][1] = min({dp[i - 1][j][0], dp[i][j - 1][0], dp[i - 1][j - 1][1]}) + 1;
            else dp[i][j][0] = min({dp[i - 1][j][1], dp[i][j - 1][1], dp[i - 1][j - 1][0]}) + 1;
            ans = max({ans, dp[i][j][0], dp[i][j][1]});
        }
    cout << ans << endl;
    return 0;
}