//
// Created by Emme.Kwok on 2026/7/9.
//
#include<bits/stdc++.h>
using namespace std;

struct node { int w, c; };

int main() {
    int v, n, t;
    cin >> v >> n >> t;
    vector<node> a[t + 1];
    for (int i = 0, wi, ci, p; i < n; i++) {
        cin >> wi >> ci >> p;
        a[p].push_back({wi, ci});
    }
    vector<int> dp(v + 1, 0);
    for (int i = 1; i <= t; i++)
        for (int j = v; j >= 0; j--)
            for (auto & k : a[i])
                if (j >= k.w) dp[j] = max(dp[j - k.w] + k.c, dp[j]);
    cout << dp[v] << endl;
    return 0;
}