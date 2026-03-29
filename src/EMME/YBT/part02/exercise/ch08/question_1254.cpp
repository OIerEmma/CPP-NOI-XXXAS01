//
// Created by Emme.Kwok on 2026/3/28.
//
#include<iostream>
#include<queue>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int n, m, sx, sy, ex, ey, vis[105][105];
char mp[105][105];
struct node {
    int x, y;
};

int bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 0;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        if (u.x == ex && u.y == ey) {
            return vis[ex][ey];
        }
        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || mp[nx][ny] == '#') continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[u.x][u.y] + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') sx = i, sy = j;
            else if (mp[i][j] == 'T') ex = i, ey = j;
        }
    }
    cout << bfs(sx, sy) << endl;
    return 0;
}
