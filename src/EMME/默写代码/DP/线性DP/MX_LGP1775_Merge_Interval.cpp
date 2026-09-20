//
// Created by Geek.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp2[i][j] = INF;
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    cout << dp[1][n] << " " << dp2[1][n] << endl;
    return 0;
}