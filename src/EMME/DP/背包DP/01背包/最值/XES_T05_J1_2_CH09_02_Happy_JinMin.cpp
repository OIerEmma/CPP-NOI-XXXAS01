//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m), p(m);
    for (int i = 0; i < m; i++) cin >> v[i] >> p[i];
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < m; i++)
        for (int j = n; j >= v[i]; j--)
            dp[j] = max(dp[j - v[i]] + p[i] * v[i], dp[j]);
    cout << dp[n] << endl;
    return 0;
}