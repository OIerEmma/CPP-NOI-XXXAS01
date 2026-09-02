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

int floodFillBfs(int r, int c) {
    queue<pair<int, int> > q;
    visited[r][c] = true;
    q.push({r, c});
    int area = 0;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        area++;
        for (int k = 0; k < K; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc]== 1) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) total++;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && grid[i][j] == 1) {
                maxIsland = max(maxIsland, floodFillBfs(i, j));
                islands++;
            }
    cout << total << " " << islands << " " << maxIsland << endl;
    return 0;
}