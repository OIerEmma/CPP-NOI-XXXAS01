//
// Created by Emme.Kwok on 2026/7/9.
//
#include<bits/stdc++.h>
using namespace std;

const long long NEG_INF = -1e18;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, P, Q;
        cin >> n >> P >> Q;
        vector<int> p(n), c(n);
        for (int i = 0; i < n; i++) cin >> p[i] >> c[i];
        // 状态：dp[i]代表前若干个武器总花费恰好为Q时的最大强度
        vector<long long> dp(Q + 1, NEG_INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = Q; j >= c[i]; j--)
                if (dp[j - c[i]] != NEG_INF) dp[j] = max(dp[j - c[i]] + p[i], dp[j]);
        int ans = -1;
        for (int i = 0; i <= Q; i++) if (dp[i] >= P) { ans = i; break; }
        cout << ans << endl;
    }
    return 0;
}