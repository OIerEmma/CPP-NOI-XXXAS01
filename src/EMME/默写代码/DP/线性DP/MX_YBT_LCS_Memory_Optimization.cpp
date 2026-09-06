//
// Created by Emme.Kwok on 2026/9/6.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = (int)s1.size(), m = (int)s2.size(), prev = 0, cur = 1;
    vector<vector<int>> dp(2, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[cur][j] = dp[prev][j - 1] + 1;
            else dp[cur][j] = max(dp[prev][j], dp[cur][j - 1]);
        }
        swap(prev, cur);
    }
    cout << dp[prev][m] << endl;
    return 0;
}