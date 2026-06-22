//
// Created by Emme.Kwok on 2026/6/1.
//
#include<iostream>
#include<vector>
using namespace std;

const int mod = 1e9 + 7, OFFSET = 2 * 1e5 + 3;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1 + OFFSET, 0);
    dp[n + OFFSET] = 1;
    for (int i = n - 1; i >= c + 1 - max(a, b); i--) {
        if (i + a > c && i + a <= n) dp[i + OFFSET] = (dp[i + OFFSET] + dp[i + a + OFFSET]) % mod;
        if (i + b > c && i + b <= n) dp[i + OFFSET] = (dp[i + OFFSET] + dp[i + b + OFFSET]) % mod;
    }
    int ans = 0;
    for (int i = c; i >= c + 1 - max(a, b); i--) ans = (ans + dp[i + OFFSET]) % mod;
    cout << ans << endl;
    return 0;
}