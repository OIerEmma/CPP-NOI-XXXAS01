//
// Created by Emme.Kwok on 2026/8/27.
//
#include<iostream>
using namespace std;

int a[51],b[51],c[51], dp[501][501];

int main() {
    int h, t, k;
    cin >> h >> t >> k;
    for (int i = 1; i <= k; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= k; i++)
        for (int j = h; j >= a[i]; j--)
            for (int l = t; l >= b[i]; l--)
                dp[j][l] = max(dp[j][l], dp[j - a[i]][l - b[i]] + c[i]);
    cout << dp[h][t] << endl;
    return 0;
}
