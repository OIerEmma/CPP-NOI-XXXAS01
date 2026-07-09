//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
    cout << dp[m] << endl;
    return 0;
}