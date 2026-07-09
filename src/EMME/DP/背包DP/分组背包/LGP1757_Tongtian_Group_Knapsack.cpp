//
// Created by Emme.Kwok on 2026/7/9.
//
#include<bits/stdc++.h>
using namespace std;

struct node { int w, c; };

int main() {
    int m, n, k = -1;
    cin >> m >> n;
    vector<node> a[101];
    for (int i = 0, wi, ci, p; i < n; i++) {
        cin >> wi >> ci >> p;
        a[p].push_back({wi, ci});
        k = max(k, p);
    }
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= k; i++)
        for (int j = m; j >= 0; j--)
            for (auto & s : a[i])
                if (j >= s.w) dp[j] = max(dp[j - s.w] + s.c, dp[j]);
    cout << dp[m] << endl;
    return 0;
}