//
// Created by Emme.Kwok on 2026/7/2.
//
#include<bits/stdc++.h>
using namespace std;

const int w[] = {1, 2, 3, 5, 10, 20};
const int n = 1000;

int main() {
    vector<int> a(n);
    int x, cnt = 0, W = 0;
    for (int i = 0; i < 6; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) a[cnt++] = w[i], W += w[i];
    }
    // 状态：dp[i]代表是否能称出i重量
    vector<bool> dp(W + 1, false);
    dp[0] = true;
    for (int i = 0; i < cnt; i++)
        for (int j = W; j >= a[i]; j--)
            dp[j] = dp[j - a[i]] || dp[j];
    int ans = 0;
    for (int i = 1; i <= W; i++) ans += dp[i];
    cout << ans << endl;
    return 0;
}