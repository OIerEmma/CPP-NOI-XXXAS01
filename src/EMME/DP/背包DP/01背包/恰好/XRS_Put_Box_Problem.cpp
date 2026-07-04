//
// Created by Emme.Kwok on 2026/7/2.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 状态：dp[i]代表是否能装出重量i
    vector<bool> dp(V + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = V; j >= a[i]; j--)
            dp[j] = dp[j] || dp[j - a[i]];
    for (int i = V; i >= 0; i--)
        if (dp[i]) { cout << V - i << endl; break; }
    return 0;
}