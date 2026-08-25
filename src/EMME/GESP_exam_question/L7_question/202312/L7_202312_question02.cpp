//
// Created by Emme.Kwok on 2026/8/18.
//
#include<bits/stdc++.h>
using namespace std;

const long long NEG = -1e18;

long long calc_score(int x, long long ci, long long ai) {
    if (x == ci) return ai;
    if (x == (ci + 1) % 3) return 2 * ai;
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1, 0), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<long long>> dp(3, vector<long long>(n + 1, NEG));
    for (int i = 0; i < 3; i++) dp[i][0] = calc_score(i, c[1], a[1]);
    for (int i = 2; i <= n; i++) {
        vector<vector<long long>> ndp(3 , vector<long long>(n + 1, NEG));
        for (int x = 0; x < 3; x++) {
            long long s = calc_score(x, c[i], a[i]);
            for (int xp = 0; xp < 3; xp++)
                for (int k = 0; k < i; k++) {
                    if (dp[xp][k] == NEG) continue;
                    if (x == xp) ndp[x][k] = max(ndp[x][k], dp[xp][k] + s);
                    else if (k + 1 <= n - 1) ndp[x][k + 1] = max(ndp[x][k + 1], dp[xp][k] + s - b[k + 1]);
                }
        }
        dp = ndp;
    }
    long long ans = NEG;
    for (int x = 0; x < 3; x++)
        for (int k = 0; k < n; k++) ans = max(ans, dp[x][k]);
    cout << ans << endl;
    return 0;
}