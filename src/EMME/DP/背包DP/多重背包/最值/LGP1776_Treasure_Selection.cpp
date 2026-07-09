//
// Created by Emme.Kwok on 2026/7/4.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> m[i];
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int k = 0; k < m[i]; k++)
            for (int j = W; j >= w[i]; j--)
                dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
    cout << dp[W] << endl;
    return 0;
}