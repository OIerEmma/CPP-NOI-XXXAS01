//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 4;
string grid[N];
bool visited[N][N];
int n, m;
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};

void floodFillBfs(int r, int c) {
  queue<pair<int, int> > q;
  q.push({r, c});
  visited[r][c] = true;
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second; q.pop();
    for (int k = 0; k < K; k++) {
      int nr = r + dr[k], nc = c + dc[k];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.' && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push({nr, nc});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> grid[i];
  if (grid[0][0] == '#' || grid[n-1][m-1] == '#') cout << "No" << endl, exit(0);
  floodFillBfs(0, 0);
  if (visited[n-1][m-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}