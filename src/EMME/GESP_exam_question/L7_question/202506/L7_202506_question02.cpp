//
// Created by Emme.Kwok on 2026/8/25.
//
#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 50005;
const int MAXN = OFFSET * 2 + 1;
const int NEG = -1e9;

int main() {
    int n;
    cin >> n;
    vector<int> dp(MAXN, NEG);
    dp[OFFSET] = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        int x = a + b, y = a - b;
        if (y > 0) {
            for (int t = MAXN - 1; t >= y; t--)
                if (dp[t - y] != NEG)
                    dp[t] = max(dp[t], dp[t - y] + x);
        } else if (y < 0) {
            for (int t = 0; t - y < MAXN; t++)
                if (dp[t - y] != NEG)
                    dp[t] = max(dp[t], dp[t - y] + x);
        } else {
            for (int t = 0; t < MAXN; t++)
                if (dp[t] != NEG)
                    dp[t] = max(dp[t], dp[t] + x);
        }
    }
    cout << (dp[OFFSET] < 0 ? 0 : dp[OFFSET]) << "\n";
    return 0;
}