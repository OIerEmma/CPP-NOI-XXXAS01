//
// Created by Geek.Kwok on 7/28/26.
//
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    int n, K;
    string s;
    cin >> n >> K >> s;

    // 第 2 步：dp[i][w][c] = 前 i 天、工作 w 天、当前连续 c 天，最小体力
    vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> >(n + 1, vector<long long>(n + 1, INF)));

    // 第 5 步：还没开始
    dp[0][0][0] = 0;

    // 第 1、6 步：按天正序
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= i; w++) {
            // 第 3、4 步（逆向/拉）：今天休息 → 填 dp[i][w][0]
            // 来源：昨天任意连续天数 c，w 不变，体力不变
            for (int c = 0; c <= w; c++) dp[i][w][0] = min(dp[i][w][0], dp[i - 1][w][c]);
            // 第 3、4 步（逆向/拉）：今天工作 → 填 dp[i][w][c]（c≥1）
            // 来源：昨天 (w-1, c-1)，体力 + c；仅当 s 为 '1'
            if (s[i - 1] == '1')
                for (int c = 1; c <= w; c++) dp[i][w][c] = min(dp[i][w][c], dp[i - 1][w - 1][c - 1] + c);
        }
    }

    // 第 7 步：体力 ≤ K 的最大 w
    for (int w = n; w >= 0; w--)
        for (int c = 0; c <= w; c++)
            if (dp[n][w][c] <= K) cout << w << endl, exit(0);

    return 0;
}