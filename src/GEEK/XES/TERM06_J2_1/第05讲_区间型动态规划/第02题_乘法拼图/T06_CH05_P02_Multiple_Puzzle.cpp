//
// Created by Geek.Kwok on 7/17/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 状态：dp[i][j] = 删空区间 [i,j] 且保留 i 和 j 的最小总得分
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1e9));
    for (int i = 1; i < n; i++) dp[i][i + 1] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] *  a[j]);
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    vector<long long> a(2 * n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i], a[n + i] = a[i];
    a[2 * n + 1] = a[1];
    vector<vector<long long>> dp(2 * n + 1, vector<long long>(2 * n + 1, 0));
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
        }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i][n + i - 1]);
    cout << ans << endl;
    return 0;
}
*/