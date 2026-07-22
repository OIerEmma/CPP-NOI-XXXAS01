//
// Created by Geek.Kwok on 7/22/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    // dp[i][j] 把i到j按照最优策略全部卖完得到的最大值
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][i] = n * v[i];

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            int t = n - j + i;
            dp[i][j] = max(dp[i+1][j] + t * v[i], dp[i][j-1] + t * v[j]);
        }

    cout << dp[1][n] << endl;
    return 0;
}