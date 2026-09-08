//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dist[405][405];
struct node {
    int x, y;
};
int n, m, x, y;

void bfs() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) dist[i][j] = -1;
    queue<node> q;
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[now.x][now.y] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m >> x >> y;
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    return 0;
}