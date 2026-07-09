//
// Created by Emme.Kwok on 2026/7/5.
//
#include<bits/stdc++.h>
using namespace std;

const int n = 6, N = 1005;
const int c[] = {1, 2, 3, 5, 10, 20};

int main() {
    vector<int> w(N);
    int cnt = 0, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) w[cnt++] = c[i];
    }
    vector<bool> dp(N + 1, false);
    dp[0] = true;
    for (int i = 0; i < cnt; i++)
        for (int j = N; j >= w[i]; j--)
            dp[j] = dp[j - w[i]] || dp[j];
    int ans = 0;
    for (int i = 1; i < N; i++) ans += dp[i];
    cout << "Total=" << ans << endl;
    return 0;
}