//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, n, c;
    cin >> V >> n >> c;
    vector<int> w(n + 1), v(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
    // dp[i]代表体力为i时最多填的体积
    vector<int> dp(c + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = c; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    for (int i = 1; i <= c; i++)
        if (dp[i] >= V) cout << c - i << endl, exit(0);
    cout << "Impossible" << endl;
    return 0;
}