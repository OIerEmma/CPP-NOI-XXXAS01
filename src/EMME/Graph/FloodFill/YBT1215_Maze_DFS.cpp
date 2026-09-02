//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 105, K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
int n, x, y, z, r;
bool vis[N][N];
char grid[N][N];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < K; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> grid[i][j];
        cin >> x >> y >> z >> r;
        if (grid[x][y] == '#' || grid[z][r] == '#') { cout << "NO\n"; continue; }
        dfs(x, y);
        cout << (vis[z][r] ? "YES" : "NO") << "\n";
    }
    return 0;
}