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
    for (int i = 0; i < n; i++)
        for (int k = 0; k < s[i]; k++)
            for (int j = m; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[m] << endl;
    return 0;
}