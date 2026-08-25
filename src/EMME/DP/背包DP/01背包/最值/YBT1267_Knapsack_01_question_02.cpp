//
// Created by Emme.Kwok on 2026/8/12.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int W, n;
    cin >> W >> n;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> c[i];
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
    cout << dp[W] << endl;
    return 0;
}