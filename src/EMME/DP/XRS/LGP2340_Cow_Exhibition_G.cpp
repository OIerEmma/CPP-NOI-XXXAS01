//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

const int x = 800000, y = 400000;
struct node {
    int iq, eq;
} a[401];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].iq >> a[i].eq;
    vector<int> dp(x + 1, -1e9);
    dp[y] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].iq >= 0) {
            for (int j = x; j >= a[i].iq; j--)
                dp[j] = max(dp[j], dp[j - a[i].iq] + a[i].eq);
        } else {
            for (int j = 0; j <= x + a[i].iq; j++)
                dp[j] = max(dp[j], dp[j - a[i].iq] + a[i].eq);
        }
    }
    int ans = 0;
    for (int i = y; i <= x; i++)
        if (dp[i] > 0) ans = max(ans, i + dp[i] - y);
    cout << ans << endl;
    return 0;
}
