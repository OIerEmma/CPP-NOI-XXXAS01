//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int dist[1005][1005];
char a[1005][1005];
struct node {
    int x, y;
};
int n, x, y, xe, ye;

int bfs() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dist[i][j] = -1;
    queue<node> q;
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.x == xe && now.y == ye) return dist[now.x][now.y];
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && dist[nx][ny] == -1 && a[nx][ny] == '0') {
                q.push({nx, ny});
                dist[nx][ny] = dist[now.x][now.y] + 1;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    cin >> x >> y >> xe >> ye;
    cout << bfs() << endl;
    return 0;
}