//
// Created by Emme.Kwok on 2026/9/11.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k = -1;
    cin >> m >> n;
    vector<pair<int, int>> a[101];
    for (int i = 0, wi, ci, p; i < n; i++) {
        cin >> wi >> ci >> p;
        a[p].push_back({wi, ci});
        k = max(k, p);
    }
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= k; i++)
        for (int j = m; j >= 0; j--)
            for (auto & s : a[i])
                if (j >= s.first) dp[j] = max(dp[j - s.first] + s.second, dp[j]);
    cout << dp[m] << endl;
    return 0;
}