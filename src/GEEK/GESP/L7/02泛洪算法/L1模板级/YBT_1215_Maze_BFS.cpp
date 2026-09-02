//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 4;
string grid[N];
bool visited[N][N];
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};
int n, sr, sc, tr, tc;

void floodFillBfs(int r, int c) {
  queue<pair<int, int> > q;
  q.push({r, c});
  visited[r][c] = true;
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    for (int k = 0; k < K; k++) {
      int nr = r + dr[k], nc = c + dc[k];
      if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == '.' && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push({nr, nc});
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(visited, false, sizeof visited);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> grid[i];
    cin >> sr >> sc >> tr >> tc;
    if (grid[sr][sc] == '#' || grid[tr][tc] == '#') { cout << "NO" << endl; continue; }
    floodFillBfs(sr, sc);
    if (visited[tr][tc]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}