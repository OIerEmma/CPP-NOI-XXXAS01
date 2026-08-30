//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<bool> dp(V + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = V; j >= a[i]; j--)
            dp[j] = dp[j] || dp[j - a[i]];
    for (int j = V; j >= 0; j--)
        if (dp[j]) cout << V - j << endl, exit(0);
    return 0;
}