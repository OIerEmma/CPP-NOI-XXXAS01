//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

struct node {
    int w, v;
} a[510];

bool cmp(node x, node y) {
    return x.w < y.w;
}

int main() {
    int n, m, l, s;
    cin >> n >> m >> l >> s;
    vector<vector<int>> dp(n + 1, vector<int>(20010, 0));
    for (int i = 1; i <= n; i++) cin >> a[i].w;
    for (int i = 1; i <= n; i++) cin >> a[i].v;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = a[i].w; j <= s + m; j++)
            dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].w] + a[i].v);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cost = max(a[i].w - l, 0);
        if (cost <= m) ans = max(ans, dp[i][s + m - cost]);
    }
    cout << ans << endl;
    return 0;
}