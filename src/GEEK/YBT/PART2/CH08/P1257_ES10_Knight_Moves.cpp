//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
using namespace std;

#define N 305

int dx[] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[] = {1, 2, -1, -2, 1, 2, -1, -2};
int t, n, sx, sy, ex, ey, vis[N][N];
struct node {int x, y; };

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> sx >> sy >> ex >> ey;
        memset(vis, -1, sizeof(vis));

        queue<node> q;
        q.push({sx, sy});
        vis[sx][sy] = 0;
        while (!q.empty()) {
            node cur = q.front(); q.pop();
            if (cur.x == ex && cur.y == ey) {
                cout << vis[ex][ey] << endl;
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny] != -1) continue;
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return 0;
}