//
// Created by Emme.Kwok on 2026/5/5.
//
#include<iostream>
using namespace std;

int M, n, w[35], c[35], dp[35][205];

int main() {
    cin >> M >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i];
    for (int i = 0; i <= M; i++) dp[0][i] = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            }
        }
    }
    cout << dp[n][M] << endl;
    return 0;
}