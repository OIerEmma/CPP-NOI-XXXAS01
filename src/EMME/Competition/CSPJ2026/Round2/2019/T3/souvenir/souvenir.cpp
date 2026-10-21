//
// Created by Emme.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

int p[105][105], f[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m;
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= n; j++) cin >> p[i][j];
    for (int i = 1; i < t; i++) {
        memset(f, 0, sizeof f);
        for (int j = 1; j <= n; j++) {
            int g = p[i + 1][j] - p[i][j];
            if (g <= 0) continue;
            for (int c = p[i][j]; c <= m; c++)
                f[c] = max(f[c], f[c - p[i][j]] + g);
        }
        m += f[m];
    }
    cout << m << endl;
    return 0;
}