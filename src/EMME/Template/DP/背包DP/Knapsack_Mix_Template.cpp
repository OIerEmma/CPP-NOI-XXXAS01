//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int W, n;
    cin >> W >> n;
    vector<int> w(n + 1), v(n + 1), m(n + 1);
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> m[i];
        if (!m[i]) {
            for (int j = w[i]; j <= W; j++)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        } else {
            int c = m[i];
            for (int use, k = 1; c > 0; k *= 2, c -= use) {
                use = min(k, c);
                int ww = use * w[i], vv = use * v[i];
                for (int j = W; j >= ww; j--)
                    dp[j] = max(dp[j - ww] + vv, dp[j]);
            }
        }
    }
    cout << dp[W] << endl;
    return 0;
}