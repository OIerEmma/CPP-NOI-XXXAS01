//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 45, M = 45, K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
int n, m, dist[N][M];
char grid[N][M];
struct node {
    int x, y;
};

void bfs(int x, int y) {
    memset(dist, -1, sizeof dist);
    queue<node> q;
    q.push({x, y});
    dist[x][y] = 1;
    while (!q.empty()) {
        node u = q.front(); q.pop();
        for (int i = 0; i < K; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1 && grid[nx][ny] == '.') {
                q.push({nx, ny});
                dist[nx][ny] = dist[u.x][u.y] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> grid[i][j];
    bfs(1, 1);
    cout << dist[n][m] << endl;
    return 0;
}