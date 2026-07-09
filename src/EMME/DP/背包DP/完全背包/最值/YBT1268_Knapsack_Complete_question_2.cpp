//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> c[i];
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j - w[i]] + c[i], dp[j]);
    cout << "max=" << dp[m] << endl;
    return 0;
}