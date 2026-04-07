//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
using namespace std;

#define N 105

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, sx, sy, ex, ey, vis[N][N];
char mp[N][N];
struct node {int x, y; };

int main() {
    memset(vis, -1, sizeof(vis));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') sx = i, sy = j;
            else if (mp[i][j] == 'T') ex = i, ey = j;
            else if (mp[i][j] == '#') vis[i][j] = 0;
        }
    }
    // L03_BFS
    queue<node> q;
    q.push({ sx, sy });
    vis[sx][sy] = 0;
    while (!q.empty()) {
        node now = q.front(); q.pop();
        if (now.x == ex && now.y == ey) {
            cout << vis[ex][ey] << endl;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] != -1) continue;
            vis[xx][yy] = vis[now.x][now.y] + 1;
            q.push({xx, yy});
        }
    }
    return 0;
}