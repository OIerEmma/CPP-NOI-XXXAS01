//
// Created by Emme.Kwok on 2026/7/4.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(n), s(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i] >> s[i];
    // 初始化
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int c = s[i];
        for (int use, k = 1; c > 0; k <<= 1, c -= use) {
            use = min(k, c);
            int ww = use * w[i], vv = use * v[i];
            for (int j = m; j >= ww; j--)
                dp[j] = max(dp[j], dp[j - ww] + vv);
        }
    }
    cout << dp[m] << endl;
    return 0;
}