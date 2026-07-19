//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // 标准模板（两种资源 ≤ 上限，求 max）
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
    // 状态：dp[i][j]代表前若干个物品，资源1不超过i，资源2不超过j时能得到的最大价值
    for (int i = 0; i < n; i++)
        for (int x = m; x >= a[i]; x--)
            for (int y = k; y >= b[i]; y--)
                dp[x][y] = max(dp[x - a[i]][y - b[i]] + c[i], dp[x][y]);
    cout << dp[m][k] << endl;
    return 0;
}

int main2() {
    // 变体：潜水员（两种资源 ≥ 下限，求 min 重量）
    int m, n, k;
    cin >> m >> n >> k;
    const int INF = 1e9;
    // 状态：dp[i][j]代表前若干个物品，资源1不小于i，资源2不小于j时能得到的最大价值
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    while (k--) {
        int o2, n2, w;
        cin >> o2 >> n2 >> w;
        for (int i = m; i >= 0; i--)
            for (int j = n; j >= 0; j--)
                dp[i][j] = min(dp[i][j], dp[max(0, i - o2)][max(0, j - n2)] + w);
    }
    cout << dp[m][n] << endl;
    return 0;
}

typedef long long ll;
const ll NEG = (ll)-1e18;

int main3() {
    // 变体：武器购买（一种资源 ≥ 下限，另一种资源 ≤ 上限，求 min 花费）
    int n, P, Q;
    cin >> n >> P >> Q;
    // 状态：dp[i][j]代表前若干个物品，资源1不小于i，资源2不超过j时能得到的最大价值
    vector<ll> dp(Q + 1, NEG);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        for (int j = Q; j >= c; j--)
            if (dp[j - c] != NEG) dp[j] = max(dp[j], dp[j - c] + p);
    }
    int ans = -1;
    for (int j = 0; j <= Q; j++) if (dp[j] >= P) { ans = j; break; }
    cout << ans << "\n";
    return 0;
}