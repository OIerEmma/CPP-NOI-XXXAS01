//
// Created by Emme.Kwok on 2026/9/11.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n + 1), v(n + 1), m(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> m[i];
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= n; i++) {
        int c = m[i];
        for (int use, k = 1; c > 0; k *= 2, c -= use) {
            use = min(k, c);
            int ww = w[i] * use, vv = v[i] * use;
            for (int j = W; j >= ww; j--)
                dp[j] = max(dp[j], dp[j - ww] + vv);
        }
    }
    cout << dp[W] << endl;
    return 0;
}