//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 4;
int n, m;
string grid[N];
bool visited[N][N];
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};

void floodFillDfs(int r, int c) {
  visited[r][c] = true;
  for (int i = 0; i < K; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.' && !visited[nr][nc])
      floodFillDfs(nr, nc);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> grid[i];
  if (grid[0][0] == '#' || grid[n-1][m-1] == '#') cout << "No" << endl, exit(0);
  floodFillDfs(0, 0);
  if (visited[n-1][m-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}