//
// Created by Emme.Kwok on 2026/7/11.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int r;
    cin >> r;
    vector<vector<int>> grid(r + 1, vector<int>(r + 1));
    for (int i = 0; i < r; i++)
        for (int j = 0; j <= i; j++)
            cin >> grid[i][j];
    vector<vector<int>> dp(r + 1, vector<int>(r + 1, 0));
    for (int i = 0; i < r; i++) dp[r - 1][i] = grid[r - 1][i];
    for (int i = r - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + grid[i][j];
    cout << dp[0][0] << endl;
    return 0;
}