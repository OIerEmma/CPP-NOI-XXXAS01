//
// Created by Emme.Kwok on 2026/9/6.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n + 1, 1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}