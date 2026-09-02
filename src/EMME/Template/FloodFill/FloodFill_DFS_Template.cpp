//
// Created by Emme.Kwok on 2026/9/1.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, m, grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

void floodfill(int r, int c) {
    vis[r][c] = true;
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc])
            floodfill(nr, nc);
    }
}

void floodfill2(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (vis[r][c] || !grid[r][c]) return;
    vis[r][c] = true;
    for (int k = 0; k < 4; k++)
        floodfill2(r + dr[k], c + dc[k]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    int islands = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] && !vis[i][j]) {
                floodfill(i, j);
                islands++;
            }
    cout << islands << endl;
    return 0;
}