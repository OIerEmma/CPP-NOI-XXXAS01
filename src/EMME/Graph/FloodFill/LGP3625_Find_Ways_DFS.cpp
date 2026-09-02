//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 105, M = 105, K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
int n, m;
bool vis[N][M], ans = false;
char grid[N][M];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int k = 0; k < K; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx == n && ny == m) { ans = true; return; }
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && grid[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> grid[i][j];
    dfs(1, 1);
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}