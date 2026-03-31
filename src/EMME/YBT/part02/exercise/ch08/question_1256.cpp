//
// Created by Emme.Kwok on 2026/3/29.
//
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int t, n, m, sx, sy, ex, ey, vis[205][205];
char mp[205][205];
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
    return -1;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == 'S') sx = i, sy = j;
                if (mp[i][j] == 'E') ex = i, ey = j;
            }
        }
        int ans = bfs(sx, sy);
        if (ans == -1) cout << "oop!" << endl;
        else cout << ans << endl;
    }
    return 0;
}