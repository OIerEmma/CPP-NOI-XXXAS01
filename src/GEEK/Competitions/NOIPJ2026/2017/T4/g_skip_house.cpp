//
// Created by Geek.Kwok on 2026/10/9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_skip_house.in", "r", stdin);
    // freopen("g_skip_house.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    const long long NEG_INF = -1e18;
    int n, d, k;
    long long max_score = 0;
    cin >> n >> d >> k;
    vector<int> dist(n + 1, 0), score(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> dist[i] >> score[i];
        if (score[i] > 0) max_score += score[i];
    }
    if (max_score < k) cout << -1 << endl, exit(0);
    // 一定有解
    // long long pre = NEG_INF + 1;
    for (int g = 0; ; g++) {
        // 状态定义 dp[i] 代表前 i 个格子通过适当的跳房子方案达到第 i 个格子的最大总得分
        vector<long long> dp(n + 1, NEG_INF);
        // 初始化
        dp[0] = 0;
        // 顺序
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dist[i] - dist[j] < max(1, d - g)) continue;
                if (dist[i] - dist[j] > d + g) break;
                // 在跳的距离范围内且自己(j)可到达的情况下则可成功往后(i)跳转
                if (dp[j] != NEG_INF) dp[i] = max(dp[i], dp[j] + score[i]);
            }
        }
        // 打印
        // for (int i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;
        // 答案
        long long ans = NEG_INF;
        for (int i = 1; i <= n; i++) if (dp[i] != NEG_INF) ans = max(ans, dp[i]);
        if (ans >= k) { cout << g << endl; break; }
        // g 与 g+1 情况下 ans 均没有变过
        // if (pre == ans) { cout << -1 << endl; break; }
        // pre = ans;
    }
    return 0;
}