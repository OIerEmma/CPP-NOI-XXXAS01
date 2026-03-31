//
// Created by Emme.Kwok on 2026/3/29.
//
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int dx[] = {2, -2, 2, -2, 1, 1, -1, -1};
const int dy[] = {1, 1, -1, -1, 2, -2, 2, -2};
int t, n, sx, sy, ex, ey, vis[305][305];
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
        for (int i = 0; i < 8; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[u.x][u.y] + 1;
        }
    }
    return -1;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> sx >> sy >> ex >> ey;
        memset(vis, 0, sizeof vis);
        cout << bfs(sx, sy) << endl;
    }
    return 0;
}