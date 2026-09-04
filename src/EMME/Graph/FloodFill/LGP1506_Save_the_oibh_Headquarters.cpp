//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

const int K = 4, N = 505, M = 505;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
char a[N][M];
int ans, n, m;
bool vis[N][M];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int k = 0; k < K; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == '0')
            dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int j = 1; j <= m; j++) {
        if (!vis[1][j] && a[1][j] == '0') dfs(1, j);
        if (!vis[n][j] && a[n][j] == '0') dfs(n, j);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i][1] && a[i][1] == '0') dfs(i, 1);
        if (!vis[i][m] && a[i][m] == '0') dfs(i, m);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j] && a[i][j] == '0') ans++;
    cout << ans << endl;
    return 0;
}