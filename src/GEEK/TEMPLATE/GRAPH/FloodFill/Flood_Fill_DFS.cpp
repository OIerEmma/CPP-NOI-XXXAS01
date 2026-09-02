//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, K = 4;
int n, m, grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};
int total, islands, maxIsland;

int floodFillDfs(int r, int c) {
    visited[r][c] = true;
    int islands = 1;
    for (int k = 0; k < K; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
            islands += floodFillDfs(nr, nc);
    }
    return islands;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) total++;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && grid[i][j] == 1) {
                maxIsland = max(maxIsland, floodFillDfs(i, j));
                islands++;
            }
    cout << total << " " << islands << " " << maxIsland << endl;
    return 0;
}