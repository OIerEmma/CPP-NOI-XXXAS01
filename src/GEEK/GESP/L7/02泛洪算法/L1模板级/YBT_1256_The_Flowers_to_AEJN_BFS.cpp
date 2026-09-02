//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 205, M = 205, K = 4;
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};
string grid[N];
int dist[N][M];
int R, C, sr, sc, tr, tc;

void floodFillDfs(int sr, int sc, int tr, int tc) {
  memset(dist, -1, sizeof dist);
  queue<pair<int, int> > q;
  q.push({sr, sc});
  dist[sr][sc] = 0;
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second; q.pop();
    if (r == tr && c == tc) break;
    for (int k = 0; k < K; k++) {
      int nr = r + dr[k], nc = c + dc[k];
      if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != '#' && dist[nr][nc] == -1)
        dist[nr][nc] = dist[r][c] + 1, q.push({nr, nc});
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
      cin >> grid[i];
      for (int j = 0; j < C; j++)
        if (grid[i][j] == 'S') sr = i, sc = j;
        else if (grid[i][j] == 'E') tr = i, tc = j;
    }
    floodFillDfs(sr, sc, tr, tc);
    if (dist[tr][tc] != -1) cout << dist[tr][tc] << endl;
    else cout << "oop!" << endl;
  }
  return 0;
}