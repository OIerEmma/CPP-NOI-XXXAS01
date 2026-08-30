//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int ts1, te1, ts2, te2, n;
    char ch;
    cin >> ts1 >> ch >> ts2 >> te1 >> ch >> te2 >> n;
    vector<int> w(n + 1), v(n + 1), m(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> m[i];
        if (!m[i]) m[i] = 1e3;
    }
    int W = te1 * 60 + te2 - (ts1 * 60 + ts2);
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= n; i++) {
        int c = m[i];
        for (int use, k = 1; c > 0; k *= 2, c -= use) {
            use = min(k, c);
            int ww = use * w[i], vv = use * v[i];
            for (int j = W; j >= ww; j--)
                dp[j] = max(dp[j - ww] + vv, dp[j]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}