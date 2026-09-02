//
// Created by Emme.Kwok on 2026/9/1.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, m, grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int bfsIsland(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    int area = 0;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        area++;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    int islands = 0, best = 0, total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] && !vis[i][j]) {
                int a = bfsIsland(i, j);
                islands++;
                total += a;
                best = max(best, a);
            }
    cout << islands << " " << best << " " << total << endl;
    return 0;
}