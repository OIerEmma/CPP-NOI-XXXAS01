//
// Created by Emme.Kwok on 2026/7/29.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    const int N = n + 1;
    long long dp[N][N][N];
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= i; w++) {
            for (int c = 0; c <= w; c++) dp[i][w][0] = min(dp[i][w][0], dp[i - 1][w][c]);
            if (s[i - 1] == '1')
                for (int c = 1; c <= w; c++) dp[i][w][c] = min(dp[i][w][c], dp[i - 1][w - 1][c - 1] + c);
        }
    for (int w = n; w >= 0; w--)
        for (int c = 0; c <= w; c++)
            if (dp[n][w][c] <= k) cout << w << endl, exit(0);
    return 0;
}