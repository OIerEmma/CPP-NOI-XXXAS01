//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

const int n = 10, m = 10, K = 4, N = 15, M = 15;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
int a[N][M], ans;
bool vis[N][M];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int k = 0; k < K; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && !a[nx][ny])
            dfs(nx, ny);
    }
}

int main() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int j = 1; j <= n; j++) {
        if (!a[1][j] && !vis[1][j]) dfs(1, j);
        if (!a[n][j] && !vis[n][j]) dfs(n, j);
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i][1] && !vis[i][1]) dfs(i, 1);
        if (!a[i][n] && !vis[i][n]) dfs(i, n);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0 && !vis[i][j]) ans++;
    cout << ans << endl;
    return 0;
}