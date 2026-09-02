//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 105, K = 4;
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};
bool grid[N][M], visited[N][M];
int n, m;

void floodFillBfs(int r, int c) {
    queue<pair<int, int> > q;
    q.push({r, c});
    visited[r][c] = true;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        for (int k = 0; k < K; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] && !visited[nr][nc])
                visited[nr][nc] = true, q.push({nr, nc});
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0;  i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int islands = 0;
    for (int i = 0;  i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] && !visited[i][j]) {
                floodFillBfs(i, j);
                islands++;
            }
    cout << islands << endl;
    return 0;
}