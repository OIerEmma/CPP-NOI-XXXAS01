//
// Created by Emme.Kwok on 2026/7/9.
//
#include<bits/stdc++.h>
using namespace std;

struct node { long long c, w; };

int main() {
    int n, m, k = -1;
    cin >> n >> m;
    vector<node> a[5];
    for (int i = 0, wi, ci, p; i < m; i++) {
        cin >> ci >> wi >> p;
        a[p].push_back({ci, wi});
        k = max(k, p);
    }
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= k; i++)
        for (int j = n; j >= 0; j--)
            for (auto & s : a[i])
                if (j >= s.c) dp[j] = max(dp[j - s.c] + s.c * s.w, dp[j]);
    cout << dp[n] << endl;
    return 0;
}