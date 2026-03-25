//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
using namespace std;

#define N 25

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m, n, sx, sy, ex, ey, ans, vis[N][N];
char mp[N][N];
bool flag;
struct node {int x, y; };

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 0;
    while (!q.empty()) {
        node now = q.front(); q.pop();
        if (now.x == ex && now.y == ey) {
            cout << vis[ex][ey] << endl;
            flag = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if (xx < 1 || xx > m || yy < 1 || yy > n || vis[xx][yy] || mp[xx][yy] == '#') continue;
            q.push({xx, yy});
            vis[xx][yy] = vis[now.x][now.y] + 1;
        }
    }
}

int main() {
    while (cin >> m >> n) {
        if (m == 0 && n == 0) {
            break;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == '@') {
                    sx = i, sy = j;
                } else if (mp[i][j] == '*') {
                    ex = i, ey = j;
                }
            }
        }
        flag = false;
        memset(vis, false, sizeof(vis));
        bfs(sx, sy);
        if (!flag) {
            cout << -1 << endl;
        }
    }
    return 0;
}