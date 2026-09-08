//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 25, K = 4;
int n, m, x, y;
bool vis[N][N];
char grid[N][N];
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};

int dfs(int x, int y) {
    vis[x][y] = true;
    int ans = 1;
    for (int k = 0; k < K; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && grid[nx][ny] == '.')
            ans += dfs(nx, ny);
    }
    return ans;
}

int main() {
    while (true) {
        cin >> m >> n;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '@') x = i, y = j;
            }
        memset(vis, false, sizeof vis);
        cout << dfs(x, y) << "\n";
    }
    return 0;
}