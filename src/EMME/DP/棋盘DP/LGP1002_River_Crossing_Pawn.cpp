//
// Created by Emme.Kwok on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;

const int x[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int y[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int bx, by, cx, cy;
    cin >> bx >> by >> cx >> cy;
    bx += 2, by += 2, cx += 2, cy += 2;
    vector<vector<long long>> dp(bx + 1, vector<long long>(by + 1, 0));
    dp[2][1] = 1;
    vector<vector<bool>> s(bx + 1, vector<bool>(by + 1, false));
    for (int i = 0; i <= 8; i++) s[cx + x[i]][cy + y[i]] = true;
    for (int i = 2; i <= bx; i++)
        for (int j = 2; j <= by; j++) {
            if (s[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    cout << dp[bx][by] << endl;
    return 0;
}