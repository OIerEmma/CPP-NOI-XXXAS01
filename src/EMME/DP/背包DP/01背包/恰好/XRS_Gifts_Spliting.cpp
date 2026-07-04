//
// Created by Emme.Kwok on 2026/7/2.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
    // 状态：dp[i]代表是否可分出i价值
    vector<bool> dp(s + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = s; j >= a[i]; j--)
            dp[j] = dp[j] || dp[j - a[i]];
    for (int j = s / 2; j >= 0; j--)
        if (dp[j]) cout << s - 2 * j << endl, exit(0);
    return 0;
}