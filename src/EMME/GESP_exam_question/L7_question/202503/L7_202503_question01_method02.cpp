//
// Created by Emme.Kwok on 2026/8/29.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505, MAXK = 25;
int n, m, k;
vector<int> g[MAXN];
bool f[MAXK][MAXN][MAXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) f[0][i][i] = true;
    for (int t = 1; t <= k; t++)
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++)
                if (f[t - 1][x][y])
                    for (int j = 0; j < (int)g[y].size(); j++)
                        f[t][x][g[y][j]] = true;
    for (int i = 1; i <= n; i++)
        for (int t = 1; t <= k; t++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) cnt += f[t][i][j];
            cout << cnt << (t == k ? "\n" : " ");
        }
    return 0;
}