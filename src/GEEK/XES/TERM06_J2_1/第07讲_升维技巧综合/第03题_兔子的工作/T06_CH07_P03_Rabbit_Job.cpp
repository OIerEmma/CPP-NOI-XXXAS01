//
// Created by Geek.Kwok on 7/28/26.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, K;
    string s;
    cin >> n >> K >> s;
    s = " " + s;
    // 定义状态：dp[i][w][k] 表示前i天中工作了w天且当前连续了k天的最小体力
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 1e9)));
    // 初始化：前i天中工作了0天且当前连续了0天的最小体力为0
    for (int i = 0; i <= n; i++) dp[i][0][0] = 0;
    // 顺序
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= i; w++) {
            // 第i天选择休息（休息日被动休息或工作日但主动选择休息），则从前i-1天中工作了w天且连续了k天中找出其中的最小体力
            for (int k = 0; k <= w; k++)
                dp[i][w][0]= min(dp[i][w][0], dp[i - 1][w][k]);
            // 第i天选择工作（工作日且主动选择工作），则从前i-1天中工作了w-1天且连续了k-1天中的最小值 + 第i天工作所消耗的体力值k
            if (s[i] == '1')
                for (int k = 1; k <= w; k++) dp[i][w][k] = dp[i - 1][w - 1][k - 1] + k;
        }
    }
    // 答案
    for (int i = n; i >= 0; i--)
        for (int w = 0; w <= i; w++)
            if (dp[n][i][w] <= K) cout << i << endl, exit(0);
    return 0;
}