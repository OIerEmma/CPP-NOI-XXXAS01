//
// Created by Emme.Kwok on 2026/8/27.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, S0, m;
    cin >> n >> S0 >> m;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<int> Si(m), ci(m);
    for (int i = 0; i < m; i++) cin >> Si[i] >> ci[i];
    int Smax = S0;
    for (int i = 0; i < m; i++) Smax = max(Smax, Si[i]);
    vector<int> dp(Smax + 1, 0);
    for (int i = 0; i < n; i++)
        for (int s = Smax; s >= w[i]; s--)
            dp[s] = max(dp[s], dp[s - w[i]] + v[i]);
    for (int s = 1; s <= Smax; s++)
        dp[s] = max(dp[s], dp[s - 1]);
    int ans = dp[S0];
    for (int i = 0; i < m; i++)
        ans = max(ans, dp[Si[i]] - ci[i]);
    cout << ans << endl;
    return 0;
}