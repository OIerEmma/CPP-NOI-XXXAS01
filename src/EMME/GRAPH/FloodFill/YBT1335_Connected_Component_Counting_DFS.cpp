//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 105, M = 105, K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
int n, m, grid[N][M], ans;
bool vis[N][M];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < K; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && grid[nx][ny])
            dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> grid[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && grid[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    cout << ans << endl;
    return 0;
}