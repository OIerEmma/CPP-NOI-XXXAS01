//
// Created by Emme.Kwok on 2026/8/27.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    int ans = 0;
    for (int last = 0; last < N; last++) {
        vector<int> dp(T, 0);
        for (int i = 0; i < N; i++) if (i != last) {
            for (int t = T - 1; t >= A[i]; t--)
                dp[t] = max(dp[t], dp[t - A[i]] + B[i]);
        }
        int best = 0;
        for (int t = 0; t <= T - 1; t++) best = max(best, dp[t]);
        ans = max(ans, best + B[last]);
    }
    cout << ans << endl;
    return 0;
}