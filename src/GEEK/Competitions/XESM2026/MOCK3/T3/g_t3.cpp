//
// Created by Geek.Kwok on 2026/10/30.
//
#include<bits/stdc++.h>
using namespace std;

struct node { int s, q, h; } a[1005];
bool cmp(node x, node y) { return x.s < y.s; }
int m, k, n, c, dp[1005][10005][2];

int main() {
    freopen("baker.in", "r", stdin);
    freopen("baker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> m >> k >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i].s >> a[i].q >> a[i].h;
    sort(a + 1, a + n + 1, cmp);
    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= a[i].s * m; j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            int cost = a[i].q;
            if (j >= cost) {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - cost][0] + a[i].h);
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - cost][1] + a[i].h);
            }
            cost = (a[i].q + 1) / 2;
            if (j >= cost && c == 1)
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - cost][0] + a[i].h);
        }
    int ans = 0;
    for (int i = 0; i <= k * m; i++)
        ans = max(ans, max(dp[n][i][0], dp[n][i][1]));
    cout << ans << endl;
    return 0;
}