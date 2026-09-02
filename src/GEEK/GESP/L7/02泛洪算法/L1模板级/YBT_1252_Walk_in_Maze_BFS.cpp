//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 105, K = 4;
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};
string grid[N];
int dist[N][M];
int R, C;

void floodFillBfs(int r, int c) {
    memset(dist, -1, sizeof dist);
    queue<pair<int, int> > q;
    q.push({r, c});
    dist[r][c] = 1;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int k = 0; k < K; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == '.' && dist[nr][nc] == -1)
                dist[nr][nc] = dist[r][c] + 1, q.push({nr, nc});
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) cin >> grid[i];
    floodFillBfs(0, 0);
    cout << dist[R-1][C-1] << endl;
    return 0;
}