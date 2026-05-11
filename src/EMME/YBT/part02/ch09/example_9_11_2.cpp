//
// Created by Emme.Kwok on 2026/5/5.
//
#include<iostream>
using namespace std;

int M, n, w[35], c[35], dp[205];

int main() {
    cin >> M >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i];
    for (int i = 0; i <= M; i++) dp[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = M; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    cout << dp[M] << endl;
    return 0;
}