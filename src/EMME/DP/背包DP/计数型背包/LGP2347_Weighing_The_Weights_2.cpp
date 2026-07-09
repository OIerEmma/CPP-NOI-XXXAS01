//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

const int n = 6;

int main() {
    vector<int> w = {1, 2, 3, 5, 10, 20}, cnt(n);
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> cnt[i], sum += cnt[i] * w[i];
    // dp[j]代表前若干个砝码凑成重量j时的方案数
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int c = cnt[i];
        for (int k = 1, used; c > 0; c -= used, k <<= 1) {
            used = min(c, k);
            int ww = used * w[i];
            for (int j = sum; j >= ww; j--)
                dp[j] += dp[j - ww];
        }
    }
    int ans = 0;
    for (int i = 1; i <= sum; i++) if (dp[i]) ans++;
    cout << "Total=" << ans << endl;
    return 0;
}