//
// Created by Emme.Kwok on 2026/7/17.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    cout << n - dp[1][n] << endl;
    return 0;
}