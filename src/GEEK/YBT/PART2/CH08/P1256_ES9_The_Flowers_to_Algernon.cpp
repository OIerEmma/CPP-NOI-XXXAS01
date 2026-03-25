//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
using namespace std;

#define N 205

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int t, r, c, vis[N][N], sx, sy, ex, ey;
char mp[N][N];
struct node {int x, y;};

int main() {
    cin >> t;
    while (t--) {
        memset(vis, -1, sizeof(vis));
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == 'S') sx = i, sy = j;
                else if (mp[i][j] == 'E') ex = i, ey = j;
                else if (mp[i][j] == '#') vis[i][j] = 0;
            }
        }

        bool flag = false;
        queue<node> q;
        q.push({sx, sy});
        vis[sx][sy] = 0;
        while (!q.empty()) {
            node now = q.front(); q.pop();
            if (now.x == ex && now.y == ey) {
                cout << vis[ex][ey] << endl;
                flag = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int xx = now.x + dx[i], yy = now.y + dy[i];
                if (xx < 1 || xx > r || yy < 1 || yy > c || vis[xx][yy] != -1) continue;
                vis[xx][yy] = vis[now.x][now.y] + 1;
                q.push({xx, yy});
            }
        }
        if (!flag) cout << "oop!" << endl;
    }
    return 0;
}