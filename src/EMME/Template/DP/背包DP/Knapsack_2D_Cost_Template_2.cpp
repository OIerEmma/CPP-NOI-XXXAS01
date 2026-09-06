//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
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
