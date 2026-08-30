//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
    vector<long long> dp(t + 1);
    for (int i = 1; i <= m; i++)
        for (int j = a[i]; j <= t; j++)
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
    cout << dp[t] << endl;
    return 0;
}