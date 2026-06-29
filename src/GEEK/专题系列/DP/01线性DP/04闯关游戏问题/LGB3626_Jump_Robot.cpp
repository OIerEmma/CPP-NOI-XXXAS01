//
// Created by Geek.Kwok on 5/14/26.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int INF = 1e9;
    // DP[i] 从第1格跳转至第i格的最少次数
    vector<int> dp(n + 1, INF);
    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        // 是否能跳到 i * 2
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2]) + 1;
        else dp[i] = min(dp[i + 1], dp[i - 1]) + 1;
    }
    cout << dp[n] << endl;
    return 0;
}