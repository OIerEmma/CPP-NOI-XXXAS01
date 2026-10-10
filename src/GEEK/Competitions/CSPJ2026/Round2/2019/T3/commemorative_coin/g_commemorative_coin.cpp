//
// Created by Geek.Kwok on 2026/10/10.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_commemorative_coin.in", "r", stdin);
    // freopen("g_commemorative_coin.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    const int MAXN = 105;
    const int MAXC = 10005;
    int p[MAXN][MAXN];
    int dp[MAXC]; // dp[c] = max profit (extra coins) when spending at most c coins today
    int T, N, M;
    cin >> T >> N >> M;
    for (int i = 1; i <= T; i++)
        for (int j = 1; j <= N; j++)
            cin >> p[i][j];
    for (int i = 1; i < T; i++) { // trade from day i to day i+1
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= N; j++) {
            int cost = p[i][j], gain = p[i + 1][j] - p[i][j];
            if (gain <= 0) continue; // never buy an item that loses money
            for (int c = cost; c <= M; c++) // unbounded knapsack: c goes upward
                dp[c] = max(dp[c], dp[c - cost] + gain);
        }
        M += dp[M]; // money on day i+1
    }
    cout << M << endl;
    return 0;
}