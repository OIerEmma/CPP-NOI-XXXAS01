//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, M, T;
    cin >> n >> M >> T;
    vector<int> m(n), t(n);
    for (int i = 0; i < n; i++) cin >> m[i] >> t[i];
    vector<vector<int>> dp(M + 1, vector<int>(T + 1, 0));
    for (int i = 0; i < n; i++)
        for (int x = M; x >= m[i]; x--)
            for (int y = T; y >= t[i]; y--)
                dp[x][y] = max(dp[x][y], dp[x - m[i]][y - t[i]] + 1);
    cout << dp[M][T] << endl;
    return 0;
}