//
// Created by Emme.Kwok on 2026/9/10.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int g = 1; g <= i; g++)
            dp[i] = max(dp[i], dp[i - g] + a[g]);
    cout << dp[n] << endl;
    return 0;
}