//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 4;
const int dr[K] = {-1, 1, 0 , 0};
const int dc[K] = {0, 0, -1, 1};
string grid[N];
bool visited[N][N];
int n, m, sr, sc;

int floodFillBfs(int r, int c) {
    queue<pair<int, int> > q;
    q.push({r, c});
    visited[r][c] = true;
    int area = 0;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        area++;
        for (int k = 0; k < K; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return area;
}

int main() {
    while (cin >> m >> n) {
        if (n == 0 && m == 0) break;
        memset(visited, false, sizeof visited);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < m; j++) if (grid[i][j] == '@') sr = i, sc = j;
        }
        cout << floodFillBfs(sr, sc) << endl;
    }
    return 0;
}