//
// Created by Geek.Kwok on 2026/9/2.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1005, M = 1005, K = 4;
const int dr[K] = {-1, 1, 0, 0};
const int dc[K] = {0, 0, -1, 1};
string grid[N];
bool visited[N][M];
int n, m;

void floodFillDfs(int r, int c) {
    visited[r][c] = true;
    for (int k = 0; k < K; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '0' && !visited[nr][nc])
            floodFillDfs(nr, nc);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> grid[i];
    int islands = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] != '0' && !visited[i][j]) {
                floodFillDfs(i, j);
                islands++;
            }
    cout << islands << endl;
    return 0;
}