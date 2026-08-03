//
// Created by Emme.Kwok on 2026/8/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, A, B;
    cin >> n >> A >> B;
    vector<int> a(n), b(n), v(n);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(A + 1, vector<int>(B + 1, 0)));
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> v[i];
    for (int i = 0; i < n; i++)
        for (int x = 0; x <= A; x++)
            for (int y = 0; y <= B; y++) {
                dp[i][x][y] = dp[i - 1][x][y];
                if (x <= a[i] && y <= b[i]) dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x - a[i]][y - b[i]] + v[i]);
            }
    cout << dp[n - 1][A][B] << endl;
    return 0;
}