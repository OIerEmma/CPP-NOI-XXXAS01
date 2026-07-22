//
// Created by Geek.Kwok on 7/22/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) dp[i][i] = true, cnt[1]++;
    for (int i = 0; i + 1 < n; i++) if (s[i] == s[i + 1]) dp[i][i + 1] = true, cnt[2]++;
    for (int len = 3; len <= n; len++)
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true, cnt[len]++;
        }
    for (int k = 1; k <= n; k++) cout << cnt[k] << " ";
    return 0;
}